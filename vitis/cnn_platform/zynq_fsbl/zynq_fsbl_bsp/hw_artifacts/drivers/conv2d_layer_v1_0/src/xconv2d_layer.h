// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCONV2D_LAYER_H
#define XCONV2D_LAYER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xconv2d_layer_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XConv2d_layer_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XConv2d_layer;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XConv2d_layer_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XConv2d_layer_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XConv2d_layer_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XConv2d_layer_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XConv2d_layer_Initialize(XConv2d_layer *InstancePtr, u16 DeviceId);
XConv2d_layer_Config* XConv2d_layer_LookupConfig(u16 DeviceId);
int XConv2d_layer_CfgInitialize(XConv2d_layer *InstancePtr, XConv2d_layer_Config *ConfigPtr);
#else
int XConv2d_layer_Initialize(XConv2d_layer *InstancePtr, const char* InstanceName);
int XConv2d_layer_Release(XConv2d_layer *InstancePtr);
#endif

void XConv2d_layer_Start(XConv2d_layer *InstancePtr);
u32 XConv2d_layer_IsDone(XConv2d_layer *InstancePtr);
u32 XConv2d_layer_IsIdle(XConv2d_layer *InstancePtr);
u32 XConv2d_layer_IsReady(XConv2d_layer *InstancePtr);
void XConv2d_layer_EnableAutoRestart(XConv2d_layer *InstancePtr);
void XConv2d_layer_DisableAutoRestart(XConv2d_layer *InstancePtr);

void XConv2d_layer_Set_height(XConv2d_layer *InstancePtr, u32 Data);
u32 XConv2d_layer_Get_height(XConv2d_layer *InstancePtr);
void XConv2d_layer_Set_width(XConv2d_layer *InstancePtr, u32 Data);
u32 XConv2d_layer_Get_width(XConv2d_layer *InstancePtr);
void XConv2d_layer_Set_in_channels(XConv2d_layer *InstancePtr, u32 Data);
u32 XConv2d_layer_Get_in_channels(XConv2d_layer *InstancePtr);
void XConv2d_layer_Set_out_channels(XConv2d_layer *InstancePtr, u32 Data);
u32 XConv2d_layer_Get_out_channels(XConv2d_layer *InstancePtr);

void XConv2d_layer_InterruptGlobalEnable(XConv2d_layer *InstancePtr);
void XConv2d_layer_InterruptGlobalDisable(XConv2d_layer *InstancePtr);
void XConv2d_layer_InterruptEnable(XConv2d_layer *InstancePtr, u32 Mask);
void XConv2d_layer_InterruptDisable(XConv2d_layer *InstancePtr, u32 Mask);
void XConv2d_layer_InterruptClear(XConv2d_layer *InstancePtr, u32 Mask);
u32 XConv2d_layer_InterruptGetEnabled(XConv2d_layer *InstancePtr);
u32 XConv2d_layer_InterruptGetStatus(XConv2d_layer *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
