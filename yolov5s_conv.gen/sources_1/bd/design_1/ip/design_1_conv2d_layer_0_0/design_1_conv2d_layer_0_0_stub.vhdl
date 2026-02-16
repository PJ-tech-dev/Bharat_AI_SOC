-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2022.2 (win64) Build 3671981 Fri Oct 14 05:00:03 MDT 2022
-- Date        : Sat Feb 14 11:06:52 2026
-- Host        : Pranav_J running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               c:/Users/prana/yolov5s_conv/yolov5s_conv.gen/sources_1/bd/design_1/ip/design_1_conv2d_layer_0_0/design_1_conv2d_layer_0_0_stub.vhdl
-- Design      : design_1_conv2d_layer_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_conv2d_layer_0_0 is
  Port ( 
    s_axi_control_AWADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_AWVALID : in STD_LOGIC;
    s_axi_control_AWREADY : out STD_LOGIC;
    s_axi_control_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_WVALID : in STD_LOGIC;
    s_axi_control_WREADY : out STD_LOGIC;
    s_axi_control_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_BVALID : out STD_LOGIC;
    s_axi_control_BREADY : in STD_LOGIC;
    s_axi_control_ARADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_ARVALID : in STD_LOGIC;
    s_axi_control_ARREADY : out STD_LOGIC;
    s_axi_control_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_RVALID : out STD_LOGIC;
    s_axi_control_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC;
    input_stream_TVALID : in STD_LOGIC;
    input_stream_TREADY : out STD_LOGIC;
    input_stream_TDATA : in STD_LOGIC_VECTOR ( 15 downto 0 );
    output_stream_TVALID : out STD_LOGIC;
    output_stream_TREADY : in STD_LOGIC;
    output_stream_TDATA : out STD_LOGIC_VECTOR ( 15 downto 0 );
    weights_Clk_A : out STD_LOGIC;
    weights_Rst_A : out STD_LOGIC;
    weights_EN_A : out STD_LOGIC;
    weights_WEN_A : out STD_LOGIC_VECTOR ( 1 downto 0 );
    weights_Addr_A : out STD_LOGIC_VECTOR ( 31 downto 0 );
    weights_Din_A : out STD_LOGIC_VECTOR ( 15 downto 0 );
    weights_Dout_A : in STD_LOGIC_VECTOR ( 15 downto 0 );
    bias_Clk_A : out STD_LOGIC;
    bias_Rst_A : out STD_LOGIC;
    bias_EN_A : out STD_LOGIC;
    bias_WEN_A : out STD_LOGIC_VECTOR ( 1 downto 0 );
    bias_Addr_A : out STD_LOGIC_VECTOR ( 31 downto 0 );
    bias_Din_A : out STD_LOGIC_VECTOR ( 15 downto 0 );
    bias_Dout_A : in STD_LOGIC_VECTOR ( 15 downto 0 );
    bias_Clk_B : out STD_LOGIC;
    bias_Rst_B : out STD_LOGIC;
    bias_EN_B : out STD_LOGIC;
    bias_WEN_B : out STD_LOGIC_VECTOR ( 1 downto 0 );
    bias_Addr_B : out STD_LOGIC_VECTOR ( 31 downto 0 );
    bias_Din_B : out STD_LOGIC_VECTOR ( 15 downto 0 );
    bias_Dout_B : in STD_LOGIC_VECTOR ( 15 downto 0 )
  );

end design_1_conv2d_layer_0_0;

architecture stub of design_1_conv2d_layer_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axi_control_AWADDR[5:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[31:0],s_axi_control_WSTRB[3:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[5:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[31:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_clk,ap_rst_n,interrupt,input_stream_TVALID,input_stream_TREADY,input_stream_TDATA[15:0],output_stream_TVALID,output_stream_TREADY,output_stream_TDATA[15:0],weights_Clk_A,weights_Rst_A,weights_EN_A,weights_WEN_A[1:0],weights_Addr_A[31:0],weights_Din_A[15:0],weights_Dout_A[15:0],bias_Clk_A,bias_Rst_A,bias_EN_A,bias_WEN_A[1:0],bias_Addr_A[31:0],bias_Din_A[15:0],bias_Dout_A[15:0],bias_Clk_B,bias_Rst_B,bias_EN_B,bias_WEN_B[1:0],bias_Addr_B[31:0],bias_Din_B[15:0],bias_Dout_B[15:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "conv2d_layer,Vivado 2022.2";
begin
end;
