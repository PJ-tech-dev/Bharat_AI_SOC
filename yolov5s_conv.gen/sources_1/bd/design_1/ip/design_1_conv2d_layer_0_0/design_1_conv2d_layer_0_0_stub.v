// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2022.2 (win64) Build 3671981 Fri Oct 14 05:00:03 MDT 2022
// Date        : Sat Feb 14 11:06:52 2026
// Host        : Pranav_J running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               c:/Users/prana/yolov5s_conv/yolov5s_conv.gen/sources_1/bd/design_1/ip/design_1_conv2d_layer_0_0/design_1_conv2d_layer_0_0_stub.v
// Design      : design_1_conv2d_layer_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "conv2d_layer,Vivado 2022.2" *)
module design_1_conv2d_layer_0_0(s_axi_control_AWADDR, 
  s_axi_control_AWVALID, s_axi_control_AWREADY, s_axi_control_WDATA, s_axi_control_WSTRB, 
  s_axi_control_WVALID, s_axi_control_WREADY, s_axi_control_BRESP, s_axi_control_BVALID, 
  s_axi_control_BREADY, s_axi_control_ARADDR, s_axi_control_ARVALID, 
  s_axi_control_ARREADY, s_axi_control_RDATA, s_axi_control_RRESP, s_axi_control_RVALID, 
  s_axi_control_RREADY, ap_clk, ap_rst_n, interrupt, input_stream_TVALID, 
  input_stream_TREADY, input_stream_TDATA, output_stream_TVALID, output_stream_TREADY, 
  output_stream_TDATA, weights_Clk_A, weights_Rst_A, weights_EN_A, weights_WEN_A, 
  weights_Addr_A, weights_Din_A, weights_Dout_A, bias_Clk_A, bias_Rst_A, bias_EN_A, bias_WEN_A, 
  bias_Addr_A, bias_Din_A, bias_Dout_A, bias_Clk_B, bias_Rst_B, bias_EN_B, bias_WEN_B, 
  bias_Addr_B, bias_Din_B, bias_Dout_B)
/* synthesis syn_black_box black_box_pad_pin="s_axi_control_AWADDR[5:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[31:0],s_axi_control_WSTRB[3:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[5:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[31:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_clk,ap_rst_n,interrupt,input_stream_TVALID,input_stream_TREADY,input_stream_TDATA[15:0],output_stream_TVALID,output_stream_TREADY,output_stream_TDATA[15:0],weights_Clk_A,weights_Rst_A,weights_EN_A,weights_WEN_A[1:0],weights_Addr_A[31:0],weights_Din_A[15:0],weights_Dout_A[15:0],bias_Clk_A,bias_Rst_A,bias_EN_A,bias_WEN_A[1:0],bias_Addr_A[31:0],bias_Din_A[15:0],bias_Dout_A[15:0],bias_Clk_B,bias_Rst_B,bias_EN_B,bias_WEN_B[1:0],bias_Addr_B[31:0],bias_Din_B[15:0],bias_Dout_B[15:0]" */;
  input [5:0]s_axi_control_AWADDR;
  input s_axi_control_AWVALID;
  output s_axi_control_AWREADY;
  input [31:0]s_axi_control_WDATA;
  input [3:0]s_axi_control_WSTRB;
  input s_axi_control_WVALID;
  output s_axi_control_WREADY;
  output [1:0]s_axi_control_BRESP;
  output s_axi_control_BVALID;
  input s_axi_control_BREADY;
  input [5:0]s_axi_control_ARADDR;
  input s_axi_control_ARVALID;
  output s_axi_control_ARREADY;
  output [31:0]s_axi_control_RDATA;
  output [1:0]s_axi_control_RRESP;
  output s_axi_control_RVALID;
  input s_axi_control_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
  input input_stream_TVALID;
  output input_stream_TREADY;
  input [15:0]input_stream_TDATA;
  output output_stream_TVALID;
  input output_stream_TREADY;
  output [15:0]output_stream_TDATA;
  output weights_Clk_A;
  output weights_Rst_A;
  output weights_EN_A;
  output [1:0]weights_WEN_A;
  output [31:0]weights_Addr_A;
  output [15:0]weights_Din_A;
  input [15:0]weights_Dout_A;
  output bias_Clk_A;
  output bias_Rst_A;
  output bias_EN_A;
  output [1:0]bias_WEN_A;
  output [31:0]bias_Addr_A;
  output [15:0]bias_Din_A;
  input [15:0]bias_Dout_A;
  output bias_Clk_B;
  output bias_Rst_B;
  output bias_EN_B;
  output [1:0]bias_WEN_B;
  output [31:0]bias_Addr_B;
  output [15:0]bias_Din_B;
  input [15:0]bias_Dout_B;
endmodule
