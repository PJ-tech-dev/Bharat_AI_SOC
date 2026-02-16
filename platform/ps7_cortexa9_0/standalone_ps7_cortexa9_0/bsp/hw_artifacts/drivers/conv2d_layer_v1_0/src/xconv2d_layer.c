// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xconv2d_layer.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XConv2d_layer_CfgInitialize(XConv2d_layer *InstancePtr, XConv2d_layer_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XConv2d_layer_Start(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL) & 0x80;
    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XConv2d_layer_IsDone(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XConv2d_layer_IsIdle(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XConv2d_layer_IsReady(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XConv2d_layer_EnableAutoRestart(XConv2d_layer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XConv2d_layer_DisableAutoRestart(XConv2d_layer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_AP_CTRL, 0);
}

void XConv2d_layer_Set_height(XConv2d_layer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_HEIGHT_DATA, Data);
}

u32 XConv2d_layer_Get_height(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_HEIGHT_DATA);
    return Data;
}

void XConv2d_layer_Set_width(XConv2d_layer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_WIDTH_DATA, Data);
}

u32 XConv2d_layer_Get_width(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_WIDTH_DATA);
    return Data;
}

void XConv2d_layer_Set_in_channels(XConv2d_layer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IN_CHANNELS_DATA, Data);
}

u32 XConv2d_layer_Get_in_channels(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IN_CHANNELS_DATA);
    return Data;
}

void XConv2d_layer_Set_out_channels(XConv2d_layer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_OUT_CHANNELS_DATA, Data);
}

u32 XConv2d_layer_Get_out_channels(XConv2d_layer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_OUT_CHANNELS_DATA);
    return Data;
}

void XConv2d_layer_InterruptGlobalEnable(XConv2d_layer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_GIE, 1);
}

void XConv2d_layer_InterruptGlobalDisable(XConv2d_layer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_GIE, 0);
}

void XConv2d_layer_InterruptEnable(XConv2d_layer *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IER);
    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IER, Register | Mask);
}

void XConv2d_layer_InterruptDisable(XConv2d_layer *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IER);
    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IER, Register & (~Mask));
}

void XConv2d_layer_InterruptClear(XConv2d_layer *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XConv2d_layer_WriteReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_ISR, Mask);
}

u32 XConv2d_layer_InterruptGetEnabled(XConv2d_layer *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_IER);
}

u32 XConv2d_layer_InterruptGetStatus(XConv2d_layer *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XConv2d_layer_ReadReg(InstancePtr->Control_BaseAddress, XCONV2D_LAYER_CONTROL_ADDR_ISR);
}

