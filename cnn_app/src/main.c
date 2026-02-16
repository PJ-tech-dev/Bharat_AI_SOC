#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// ✅ Bare metal replacements (removed <unistd.h> and <time.h>)
#include "sleep.h"          // provides usleep() for bare metal
#include "xtime_l.h"        // provides XTime timing for Zynq

// Xilinx driver includes
#include "xaxidma.h"
#include "xparameters.h"
#include "xil_cache.h"
#include "xil_io.h"

// ============================================================================
// CONFIGURATION - Memory Map from Vivado Address Editor
// ============================================================================

#define CNN_BASE_ADDR           0x40000000        // conv2d_layer_0 base

// AXI-Lite Control Register Offsets (STANDARD HLS)
#define XCONV2D_CTRL_AP_CTRL    0x00              // Control register
#define XCONV2D_CTRL_AP_STATUS  0x04              // Status register

// Control bits
#define AP_START_BIT            0x01              // Start inference
#define AP_DONE_BIT             0x02              // Done flag
#define AP_IDLE_BIT             0x04              // Idle flag
#define AP_READY_BIT            0x08              // Ready flag

// DMA Configuration
#define DMA_DEVICE_ID           XPAR_XAXIDMA_0_BASEADDR

// DDR Memory Addresses (from README)
#define IMG_INPUT_ADDR          0x10000000        // Input image
#define IMG_OUTPUT_ADDR         0x20000000        // Output results
#define IMG_INPUT_SIZE          (28 * 28 * 2)     // 28x28 x 16-bit
#define IMG_OUTPUT_SIZE         (10 * 4)          // 10 classes x 32-bit

#define NUM_CLASSES             10
#define IMAGE_HEIGHT            28
#define IMAGE_WIDTH             28

// Performance tuning
#define DMA_SPIN_COUNT          50                // Spin-wait iterations before sleep
#define DMA_SLEEP_US            100               // Sleep interval (microseconds)

// ============================================================================
// GLOBAL VARIABLES
// ============================================================================

XAxiDma AxiDmaInstance;

// ============================================================================
// UTILITY FUNCTIONS
// ============================================================================

/**
 * get_time_ms() - Get elapsed time in milliseconds using Zynq hardware timer
 *
 * Uses XTime (Global Timer) which runs at XPAR_CPU_CORE_CLOCK_FREQ_HZ/2 frequency.
 * This replaces the Linux clock_gettime(CLOCK_MONOTONIC) approach.
 *
 * Returns: Current time in milliseconds
 */
static uint64_t get_time_ms(void) {
    XTime tCur;
    XTime_GetTime(&tCur);
    // Convert hardware timer counts to milliseconds
    return (uint64_t)(tCur / (XPAR_CPU_CORE_CLOCK_FREQ_HZ / 2 / 1000));
}

static void print_header(const char *title) {
    printf("\n============================================================\n");
    printf("  %s\n", title);
    printf("============================================================\n");
}

static void print_step(const char *step, const char *detail) {
    printf("\n  [%s] %s\n", step, detail);
}

// ============================================================================
// CNN CONTROL FUNCTIONS
// ============================================================================

static void cnn_start(void) {
    print_step("CNN", "Writing START bit to control register");
    printf("       Address: 0x%08x, Value: 0x%02x\n",
           (unsigned int)(CNN_BASE_ADDR + XCONV2D_CTRL_AP_CTRL),
           (unsigned int)AP_START_BIT);
    Xil_Out32(CNN_BASE_ADDR + XCONV2D_CTRL_AP_CTRL, AP_START_BIT);
}

static uint32_t cnn_read_status(void) {
    return Xil_In32(CNN_BASE_ADDR + XCONV2D_CTRL_AP_STATUS);
}

/**
 * cnn_wait_done() - Poll CNN status register until inference completes
 *
 * @timeout_ms: Timeout in milliseconds
 * Returns: 0 on success, -1 on timeout
 */
static int cnn_wait_done(int timeout_ms) {
    uint64_t start = get_time_ms();
    uint32_t status;

    print_step("CNN", "Waiting for completion...");

    while ((get_time_ms() - start) < (uint64_t)timeout_ms) {
        status = cnn_read_status();

        if (status & AP_DONE_BIT) {
            unsigned long elapsed = (unsigned long)(get_time_ms() - start);
            // ✅ Fixed: %lu with (unsigned long) cast instead of %llu
            printf("       Complete! Status=0x%02x, Time=%lums\n",
                   (unsigned int)status, elapsed);
            return 0;
        }

        usleep(10000);  // 10ms - CNN inference is slow, no need for tight loop
    }

    printf("       TIMEOUT! Status=0x%02x\n",
           (unsigned int)cnn_read_status());
    return -1;
}

// ============================================================================
// DMA FUNCTIONS
// ============================================================================

static int dma_init(void) {
    int status;
    XAxiDma_Config *config;

    print_step("DMA", "Initializing AXI DMA");

    config = XAxiDma_LookupConfig(XPAR_XAXIDMA_0_BASEADDR);
    if (!config) {
        printf("       DMA config lookup failed\n");
        return -1;
    }

    status = XAxiDma_CfgInitialize(&AxiDmaInstance, config);
    if (status != XST_SUCCESS) {
        printf("       DMA initialization failed (status=%d)\n", status);
        return -1;
    }

    // ✅ Fixed: %lu cast for BaseAddr
    printf("       DMA ready at 0x%08lx\n", (unsigned long)config->BaseAddr);
    return 0;
}

/**
 * dma_send_image() - Transfer image from DDR to CNN input via DMA MM2S
 *
 * Performs optimized polling with initial spin-wait for low-latency transfers,
 * falling back to sleep for longer operations.
 *
 * Returns: 0 on success, -1 on failure
 */
static int dma_send_image(void) {
    int status;
    uint64_t start;
    int spin_count = 0;

    print_step("DMA", "MM2S Transfer: DDR to CNN Input");
    printf("       Source: 0x%08x, Size: %d bytes\n",
           (unsigned int)IMG_INPUT_ADDR, (int)IMG_INPUT_SIZE);

    // Flush cache to ensure DMA sees fresh data
    Xil_DCacheFlushRange(IMG_INPUT_ADDR, IMG_INPUT_SIZE);

    // Check DMA not busy before transfer
    if (XAxiDma_Busy(&AxiDmaInstance, XAXIDMA_DMA_TO_DEVICE)) {
        printf("       DMA MM2S channel still busy from previous operation\n");
        return -1;
    }

    start = get_time_ms();
    status = XAxiDma_SimpleTransfer(&AxiDmaInstance,
                                    (UINTPTR)IMG_INPUT_ADDR,
                                    IMG_INPUT_SIZE,
                                    XAXIDMA_DMA_TO_DEVICE);
    if (status != XST_SUCCESS) {
        printf("       MM2S transfer failed (status=%d)\n", status);
        return -1;
    }

    // Adaptive polling: spin first, then sleep
    while (XAxiDma_Busy(&AxiDmaInstance, XAXIDMA_DMA_TO_DEVICE)) {
        if ((get_time_ms() - start) > 5000) {
            printf("       MM2S timeout\n");
            return -1;
        }

        // Spin-wait first for very fast transfers
        if (spin_count++ < DMA_SPIN_COUNT) {
            continue;
        }

        // Fall back to sleep to prevent CPU burn
        usleep(DMA_SLEEP_US);
    }

    // ✅ Fixed: %lu with (unsigned long) cast instead of %llu
    printf("       Complete (%lums)\n", (unsigned long)(get_time_ms() - start));
    return 0;
}

/**
 * dma_read_output() - Transfer CNN results from output stream to DDR via DMA S2MM
 *
 * Uses same optimized polling strategy as dma_send_image()
 *
 * Returns: 0 on success, -1 on failure
 */
static int dma_read_output(void) {
    int status;
    uint64_t start;
    int spin_count = 0;

    print_step("DMA", "S2MM Transfer: CNN Output to DDR");
    printf("       Destination: 0x%08x, Size: %d bytes\n",
           (unsigned int)IMG_OUTPUT_ADDR, (int)IMG_OUTPUT_SIZE);

    // Invalidate cache range to prepare for fresh data from DMA
    Xil_DCacheInvalidateRange(IMG_OUTPUT_ADDR, IMG_OUTPUT_SIZE);

    // Check DMA not busy before transfer
    if (XAxiDma_Busy(&AxiDmaInstance, XAXIDMA_DEVICE_TO_DMA)) {
        printf("       DMA S2MM channel still busy from previous operation\n");
        return -1;
    }

    start = get_time_ms();
    status = XAxiDma_SimpleTransfer(&AxiDmaInstance,
                                    (UINTPTR)IMG_OUTPUT_ADDR,
                                    IMG_OUTPUT_SIZE,
                                    XAXIDMA_DEVICE_TO_DMA);
    if (status != XST_SUCCESS) {
        printf("       S2MM transfer failed (status=%d)\n", status);
        return -1;
    }

    // Adaptive polling: spin first, then sleep
    while (XAxiDma_Busy(&AxiDmaInstance, XAXIDMA_DEVICE_TO_DMA)) {
        if ((get_time_ms() - start) > 5000) {
            printf("       S2MM timeout\n");
            return -1;
        }

        if (spin_count++ < DMA_SPIN_COUNT) {
            continue;
        }

        usleep(DMA_SLEEP_US);
    }

    // Invalidate again to ensure fresh data
    Xil_DCacheInvalidateRange(IMG_OUTPUT_ADDR, IMG_OUTPUT_SIZE);

    // ✅ Fixed: %lu with (unsigned long) cast instead of %llu
    printf("       Complete (%lums)\n", (unsigned long)(get_time_ms() - start));
    return 0;
}

// ============================================================================
// TEST DATA GENERATION
// ============================================================================

/**
 * generate_test_image() - Create synthetic 16-bit test pattern
 *
 * Uses full 16-bit range to exercise the CNN's Q16 fixed-point capability.
 * Pattern: Values spread across 0x0000-0xFFFF using multiplication
 */
static void generate_test_image(void) {
    uint16_t *img = (uint16_t *)(UINTPTR)IMG_INPUT_ADDR;
    int i;

    print_step("TEST", "Generating synthetic input pattern");
    printf("       Image: %dx%d (%d bytes)\n",
           IMAGE_WIDTH, IMAGE_HEIGHT, (int)IMG_INPUT_SIZE);

    // Spread values across full 16-bit range
    // Multiplier 67 chosen so (i * 67) & 0xFFFF wraps smoothly
    for (i = 0; i < IMAGE_HEIGHT * IMAGE_WIDTH; i++) {
        img[i] = (uint16_t)((i * 67) & 0xFFFF);
    }

    printf("       First 8 values: ");
    for (i = 0; i < 8; i++) {
        printf("0x%04x ", img[i]);
    }
    printf("\n       Ready at 0x%08x\n", (unsigned int)IMG_INPUT_ADDR);
}

// ============================================================================
// RESULT PROCESSING
// ============================================================================

static void process_results(void) {
    uint32_t *output = (uint32_t *)(UINTPTR)IMG_OUTPUT_ADDR;
    uint32_t max_val = 0;
    int max_class = 0;
    int i;

    print_step("RESULTS", "CNN Output (10 classes)");

    for (i = 0; i < NUM_CLASSES; i++) {
        uint32_t val = output[i];
        printf("       Class %d: 0x%08x (%u)\n", i,
               (unsigned int)val, (unsigned int)val);

        if (val > max_val) {
            max_val = val;
            max_class = i;
        }
    }

    printf("\n       PREDICTED CLASS: %d (value: 0x%08x)\n",
           max_class, (unsigned int)max_val);
}

// ============================================================================
// MAIN INFERENCE PIPELINE
// ============================================================================

int main(void) {
    uint64_t t_start, t_end;

    print_header("CNN HARDWARE ACCELERATOR - INFERENCE");

    // Disable cache for DMA consistency
    Xil_DCacheDisable();
    printf("\n  CPU data cache disabled\n");

    // Initialize DMA
    if (dma_init() != 0) {
        printf("\nFATAL: DMA initialization failed\n");
        return -1;
    }

    // Generate test image
    generate_test_image();

    // ===== INFERENCE PIPELINE =====
    t_start = get_time_ms();

    // Step 1: Send image via DMA
    if (dma_send_image() != 0) {
        printf("\nDMA send failed\n");
        return -1;
    }

    // Step 2: Trigger CNN
    cnn_start();

    // Step 3: Wait for completion
    if (cnn_wait_done(2000) != 0) {
        printf("\nCNN inference timeout\n");
        return -1;
    }

    // Step 4: Read results
    if (dma_read_output() != 0) {
        printf("\nDMA read failed\n");
        return -1;
    }

    t_end = get_time_ms();

    // ===== RESULTS =====
    process_results();

    print_header("PERFORMANCE SUMMARY");
    // ✅ Fixed: %lu with (unsigned long) cast instead of %llu
    printf("  Total Time:       %lu ms\n", (unsigned long)(t_end - t_start));
    printf("  Target (CPU):     ~800 ms\n");
    printf("  Speedup:          %.2fx\n\n",
           800.0f / (float)(unsigned long)(t_end - t_start));

    printf("  Status: SUCCESS\n\n");

    return 0;
}


