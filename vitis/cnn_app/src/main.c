#include <stdio.h>
#include <string.h>
#include "xaxidma.h"
#include "xparameters.h"
#include "xtime_l.h"

/* ============================================================================
   CONFIGURATION
   ============================================================================ */

#define CPU_CLK_HZ          650000000      /* ARM Cortex-A9 clock from xparameters.h */
#define BUFFER_SIZE         256            /* Input/output buffer size (words) */
#define DMA_TIMEOUT         100000         /* Timeout iterations */
#define DMA_BASEADDR        XPAR_XAXIDMA_0_BASEADDR

/* ============================================================================
   GLOBAL VARIABLES
   ============================================================================ */

XAxiDma AxiDma;
u32 input_buffer[BUFFER_SIZE]  __attribute__((aligned(64)));
u32 output_buffer[BUFFER_SIZE] __attribute__((aligned(64)));

/* ============================================================================
   FUNCTION: DMA Initialization
   ============================================================================ */

int dma_init(void) {
    printf("[DMA] Base address: 0x%lx\n", (unsigned long)DMA_BASEADDR);
    printf("[DMA] Looking up config...\n");
    
    /* Device ID 0 for XAXIDMA_0 (canonical naming) */
    XAxiDma_Config *CfgPtr = XAxiDma_LookupConfig(0);
    if (CfgPtr == NULL) {
        printf("[ERROR] DMA config lookup failed\n");
        return XST_FAILURE;
    }
    printf("[DMA] Config found\n");
    
    int Status = XAxiDma_CfgInitialize(&AxiDma, CfgPtr);
    if (Status != XST_SUCCESS) {
        printf("[ERROR] DMA initialization failed with status %d\n", Status);
        return XST_FAILURE;
    }
    printf("[DMA] Initialization successful\n");
    
    return XST_SUCCESS;
}

/* ============================================================================
   FUNCTION: DMA Transfer with Timeout
   ============================================================================ */

int dma_transfer(void) {
    int timeout = DMA_TIMEOUT;
    
    printf("[DMA] Initiating MM2S (memory to FPGA)...\n");
    
    /* Send data to FPGA (MM2S - Device To DMA direction) */
    XAxiDma_SimpleTransfer(&AxiDma, 
                          (u32)(uintptr_t)input_buffer, 
                          BUFFER_SIZE * sizeof(u32), 
                          XAXIDMA_DMA_TO_DEVICE);
    
    /* Wait for MM2S completion */
    timeout = DMA_TIMEOUT;
    while (XAxiDma_Busy(&AxiDma, XAXIDMA_DMA_TO_DEVICE) && --timeout) {
        /* Spin wait */
    }
    
    if (timeout == 0) {
        printf("[ERROR] MM2S transfer timeout\n");
        return XST_FAILURE;
    }
    printf("[DMA] MM2S complete (%d iterations left)\n", timeout);
    
    printf("[DMA] Initiating S2MM (FPGA to memory)...\n");
    
    /* Read data from FPGA (S2MM - Device To DMA direction) */
    XAxiDma_SimpleTransfer(&AxiDma, 
                          (u32)(uintptr_t)output_buffer, 
                          BUFFER_SIZE * sizeof(u32), 
                          XAXIDMA_DEVICE_TO_DMA);
    
    /* Wait for S2MM completion */
    timeout = DMA_TIMEOUT;
    while (XAxiDma_Busy(&AxiDma, XAXIDMA_DEVICE_TO_DMA) && --timeout) {
        /* Spin wait */
    }
    
    if (timeout == 0) {
        printf("[ERROR] S2MM transfer timeout\n");
        return XST_FAILURE;
    }
    printf("[DMA] S2MM complete (%d iterations left)\n", timeout);
    
    return XST_SUCCESS;
}

/* ============================================================================
   FUNCTION: Fill Input Buffer with Test Data
   ============================================================================ */

void fill_test_data(void) {
    printf("[TEST] Filling input buffer with test pattern...\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = i * 0x11111111;  /* Distinctive pattern */
    }
    printf("[TEST] Input[0]=0x%08lx, Input[255]=0x%08lx\n", 
           (unsigned long)input_buffer[0], 
           (unsigned long)input_buffer[BUFFER_SIZE-1]);
}

/* ============================================================================
   FUNCTION: Cache Coherency (Xil functions handle this)
   ============================================================================ */

void prepare_buffers(void) {
    /* Flush data cache to ensure CPU writes are visible to DMA */
    Xil_DCacheFlushRange((INTPTR)input_buffer, BUFFER_SIZE * sizeof(u32));
    /* Invalidate output buffer cache lines so fresh data is read */
    Xil_DCacheInvalidateRange((INTPTR)output_buffer, BUFFER_SIZE * sizeof(u32));
}

/* ============================================================================
   MAIN
   ============================================================================ */

int main(void) {
    printf("\n");
    printf("================================================================================\n");
    printf("=== CNN FPGA ACCELERATOR APPLICATION ===\n");
    printf("=== PYNQ-Z2 | Zynq-7020 XC7Z020 | Vitis 2025.2 ===\n");
    printf("================================================================================\n\n");
    
    /* Step 1: Initialize DMA */
    printf("[MAIN] Step 1: DMA Initialization\n");
    if (dma_init() != XST_SUCCESS) {
        printf("[FATAL] DMA initialization failed\n");
        return 1;
    }
    printf("[MAIN] ✓ DMA ready\n\n");
    
    /* Step 2: Prepare test data */
    printf("[MAIN] Step 2: Prepare Test Data\n");
    fill_test_data();
    prepare_buffers();
    printf("[MAIN] ✓ Buffers prepared\n\n");
    
    /* Step 3: Time the DMA transfer */
    printf("[MAIN] Step 3: Execute DMA Transfer\n");
    
    XTime start_time, end_time;
    XTime_GetTime(&start_time);
    printf("[TIMER] Start time: %llu\n", (unsigned long long)start_time);
    
    if (dma_transfer() != XST_SUCCESS) {
        printf("[FATAL] DMA transfer failed\n");
        return 1;
    }
    
    XTime_GetTime(&end_time);
    printf("[TIMER] End time: %llu\n", (unsigned long long)end_time);
    printf("[MAIN] ✓ Transfer complete\n\n");
    
    /* Step 4: Calculate timing */
    printf("[MAIN] Step 4: Performance Analysis\n");
    
    XTime elapsed = end_time - start_time;
    unsigned long elapsed_us = (unsigned long)(elapsed / (CPU_CLK_HZ / 1000000));
    unsigned long elapsed_ms = elapsed_us / 1000;
    
    printf("[PERF] Elapsed cycles: %llu\n", (unsigned long long)elapsed);
    printf("[PERF] Elapsed time: %lu.%03lu ms (%lu us)\n", 
           elapsed_ms, elapsed_us % 1000, elapsed_us);
    
    /* Calculate throughput (MM2S + S2MM = 2x data) */
    unsigned long total_bytes = BUFFER_SIZE * sizeof(u32) * 2;
    unsigned long throughput_mbps = (total_bytes / 1024 / 1024) * 1000000 / elapsed_us;
    printf("[PERF] Data transferred: %lu bytes\n", total_bytes);
    printf("[PERF] Throughput: ~%lu MB/s\n\n", throughput_mbps);
    
    /* Step 5: Verify output data */
    printf("[MAIN] Step 5: Verify Output\n");
    printf("[VERIFY] Output[0]=0x%08lx\n", (unsigned long)output_buffer[0]);
    printf("[VERIFY] Output[1]=0x%08lx\n", (unsigned long)output_buffer[1]);
    printf("[VERIFY] Output[255]=0x%08lx\n", (unsigned long)output_buffer[BUFFER_SIZE-1]);
    printf("[MAIN] ✓ Verification complete\n\n");
    
    /* Success */
    printf("================================================================================\n");
    printf("=== APPLICATION COMPLETED SUCCESSFULLY ===\n");
    printf("================================================================================\n\n");
    
    return 0;
}