-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2025.2 (win64) Build 6299465 Fri Nov 14 19:35:11 GMT 2025
-- Date        : Tue Feb 17 15:10:34 2026
-- Host        : Pranav_J running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_1_conv2d_layer_0_0_stub.vhdl
-- Design      : design_1_conv2d_layer_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
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

  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_1_conv2d_layer_0_0,conv2d_layer,{}";
  attribute CORE_GENERATION_INFO : string;
  attribute CORE_GENERATION_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_1_conv2d_layer_0_0,conv2d_layer,{x_ipProduct=Vivado 2025.2,x_ipVendor=xilinx.com,x_ipLibrary=hls,x_ipName=conv2d_layer,x_ipVersion=1.0,x_ipCoreRevision=2114480171,x_ipLanguage=VERILOG,x_ipSimLanguage=MIXED,C_S_AXI_CONTROL_ADDR_WIDTH=6,C_S_AXI_CONTROL_DATA_WIDTH=32}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "HLS";
  attribute hls_module : string;
  attribute hls_module of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  attribute syn_black_box : boolean;
  attribute black_box_pad_pin : string;
  attribute syn_black_box of stub : architecture is true;
  attribute black_box_pad_pin of stub : architecture is "s_axi_control_AWADDR[5:0],s_axi_control_AWVALID,s_axi_control_AWREADY,s_axi_control_WDATA[31:0],s_axi_control_WSTRB[3:0],s_axi_control_WVALID,s_axi_control_WREADY,s_axi_control_BRESP[1:0],s_axi_control_BVALID,s_axi_control_BREADY,s_axi_control_ARADDR[5:0],s_axi_control_ARVALID,s_axi_control_ARREADY,s_axi_control_RDATA[31:0],s_axi_control_RRESP[1:0],s_axi_control_RVALID,s_axi_control_RREADY,ap_clk,ap_rst_n,interrupt,input_stream_TVALID,input_stream_TREADY,input_stream_TDATA[15:0],output_stream_TVALID,output_stream_TREADY,output_stream_TDATA[15:0],weights_Clk_A,weights_Rst_A,weights_EN_A,weights_WEN_A[1:0],weights_Addr_A[31:0],weights_Din_A[15:0],weights_Dout_A[15:0],bias_Clk_A,bias_Rst_A,bias_EN_A,bias_WEN_A[1:0],bias_Addr_A[31:0],bias_Din_A[15:0],bias_Dout_A[15:0],bias_Clk_B,bias_Rst_B,bias_EN_B,bias_WEN_B[1:0],bias_Addr_B[31:0],bias_Din_B[15:0],bias_Dout_B[15:0]";
  attribute X_INTERFACE_INFO : string;
  attribute X_INTERFACE_INFO of s_axi_control_AWADDR : signal is "xilinx.com:interface:aximm:1.0 s_axi_control AWADDR";
  attribute X_INTERFACE_MODE : string;
  attribute X_INTERFACE_MODE of s_axi_control_AWADDR : signal is "slave";
  attribute X_INTERFACE_PARAMETER : string;
  attribute X_INTERFACE_PARAMETER of s_axi_control_AWADDR : signal is "XIL_INTERFACENAME s_axi_control, ADDR_WIDTH 6, DATA_WIDTH 32, PROTOCOL AXI4LITE, READ_WRITE_MODE READ_WRITE, FREQ_HZ 100000000, ID_WIDTH 0, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 0, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.0, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of s_axi_control_AWVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control AWVALID";
  attribute X_INTERFACE_INFO of s_axi_control_AWREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control AWREADY";
  attribute X_INTERFACE_INFO of s_axi_control_WDATA : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WDATA";
  attribute X_INTERFACE_INFO of s_axi_control_WSTRB : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WSTRB";
  attribute X_INTERFACE_INFO of s_axi_control_WVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WVALID";
  attribute X_INTERFACE_INFO of s_axi_control_WREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WREADY";
  attribute X_INTERFACE_INFO of s_axi_control_BRESP : signal is "xilinx.com:interface:aximm:1.0 s_axi_control BRESP";
  attribute X_INTERFACE_INFO of s_axi_control_BVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control BVALID";
  attribute X_INTERFACE_INFO of s_axi_control_BREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control BREADY";
  attribute X_INTERFACE_INFO of s_axi_control_ARADDR : signal is "xilinx.com:interface:aximm:1.0 s_axi_control ARADDR";
  attribute X_INTERFACE_INFO of s_axi_control_ARVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control ARVALID";
  attribute X_INTERFACE_INFO of s_axi_control_ARREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control ARREADY";
  attribute X_INTERFACE_INFO of s_axi_control_RDATA : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RDATA";
  attribute X_INTERFACE_INFO of s_axi_control_RRESP : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RRESP";
  attribute X_INTERFACE_INFO of s_axi_control_RVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RVALID";
  attribute X_INTERFACE_INFO of s_axi_control_RREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RREADY";
  attribute X_INTERFACE_INFO of ap_clk : signal is "xilinx.com:signal:clock:1.0 ap_clk CLK";
  attribute X_INTERFACE_MODE of ap_clk : signal is "slave";
  attribute X_INTERFACE_PARAMETER of ap_clk : signal is "XIL_INTERFACENAME ap_clk, ASSOCIATED_BUSIF s_axi_control:input_stream:output_stream, ASSOCIATED_RESET ap_rst_n, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of ap_rst_n : signal is "xilinx.com:signal:reset:1.0 ap_rst_n RST";
  attribute X_INTERFACE_MODE of ap_rst_n : signal is "slave";
  attribute X_INTERFACE_PARAMETER of ap_rst_n : signal is "XIL_INTERFACENAME ap_rst_n, POLARITY ACTIVE_LOW, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of interrupt : signal is "xilinx.com:signal:interrupt:1.0 interrupt INTERRUPT";
  attribute X_INTERFACE_MODE of interrupt : signal is "master";
  attribute X_INTERFACE_PARAMETER of interrupt : signal is "XIL_INTERFACENAME interrupt, SENSITIVITY LEVEL_HIGH, PortWidth 1";
  attribute X_INTERFACE_INFO of input_stream_TVALID : signal is "xilinx.com:interface:axis:1.0 input_stream TVALID";
  attribute X_INTERFACE_MODE of input_stream_TVALID : signal is "slave";
  attribute X_INTERFACE_PARAMETER of input_stream_TVALID : signal is "XIL_INTERFACENAME input_stream, TDATA_NUM_BYTES 2, TUSER_WIDTH 0, TDEST_WIDTH 0, TID_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 0, FREQ_HZ 100000000, PHASE 0.0, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of input_stream_TREADY : signal is "xilinx.com:interface:axis:1.0 input_stream TREADY";
  attribute X_INTERFACE_INFO of input_stream_TDATA : signal is "xilinx.com:interface:axis:1.0 input_stream TDATA";
  attribute X_INTERFACE_INFO of output_stream_TVALID : signal is "xilinx.com:interface:axis:1.0 output_stream TVALID";
  attribute X_INTERFACE_MODE of output_stream_TVALID : signal is "master";
  attribute X_INTERFACE_PARAMETER of output_stream_TVALID : signal is "XIL_INTERFACENAME output_stream, TDATA_NUM_BYTES 2, TUSER_WIDTH 0, TDEST_WIDTH 0, TID_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 0, FREQ_HZ 100000000, PHASE 0.0, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of output_stream_TREADY : signal is "xilinx.com:interface:axis:1.0 output_stream TREADY";
  attribute X_INTERFACE_INFO of output_stream_TDATA : signal is "xilinx.com:interface:axis:1.0 output_stream TDATA";
  attribute X_INTERFACE_INFO of weights_Clk_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA CLK";
  attribute X_INTERFACE_MODE of weights_Clk_A : signal is "master";
  attribute X_INTERFACE_PARAMETER of weights_Clk_A : signal is "XIL_INTERFACENAME weights_PORTA, MEM_WIDTH 16, MEM_SIZE 2, MASTER_TYPE BRAM_CTRL, MEM_ECC NONE, READ_LATENCY 1";
  attribute X_INTERFACE_INFO of weights_Rst_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA RST";
  attribute X_INTERFACE_INFO of weights_EN_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA EN";
  attribute X_INTERFACE_INFO of weights_WEN_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA WE";
  attribute X_INTERFACE_INFO of weights_Addr_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA ADDR";
  attribute X_INTERFACE_INFO of weights_Din_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA DIN";
  attribute X_INTERFACE_INFO of weights_Dout_A : signal is "xilinx.com:interface:bram:1.0 weights_PORTA DOUT";
  attribute X_INTERFACE_INFO of bias_Clk_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA CLK";
  attribute X_INTERFACE_MODE of bias_Clk_A : signal is "master";
  attribute X_INTERFACE_PARAMETER of bias_Clk_A : signal is "XIL_INTERFACENAME bias_PORTA, MEM_WIDTH 16, MEM_SIZE 2, MASTER_TYPE BRAM_CTRL, MEM_ECC NONE, READ_LATENCY 1";
  attribute X_INTERFACE_INFO of bias_Rst_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA RST";
  attribute X_INTERFACE_INFO of bias_EN_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA EN";
  attribute X_INTERFACE_INFO of bias_WEN_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA WE";
  attribute X_INTERFACE_INFO of bias_Addr_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA ADDR";
  attribute X_INTERFACE_INFO of bias_Din_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA DIN";
  attribute X_INTERFACE_INFO of bias_Dout_A : signal is "xilinx.com:interface:bram:1.0 bias_PORTA DOUT";
  attribute X_INTERFACE_INFO of bias_Clk_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB CLK";
  attribute X_INTERFACE_MODE of bias_Clk_B : signal is "master";
  attribute X_INTERFACE_PARAMETER of bias_Clk_B : signal is "XIL_INTERFACENAME bias_PORTB, MEM_WIDTH 16, MEM_SIZE 2, MASTER_TYPE BRAM_CTRL, MEM_ECC NONE, READ_LATENCY 1";
  attribute X_INTERFACE_INFO of bias_Rst_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB RST";
  attribute X_INTERFACE_INFO of bias_EN_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB EN";
  attribute X_INTERFACE_INFO of bias_WEN_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB WE";
  attribute X_INTERFACE_INFO of bias_Addr_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB ADDR";
  attribute X_INTERFACE_INFO of bias_Din_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB DIN";
  attribute X_INTERFACE_INFO of bias_Dout_B : signal is "xilinx.com:interface:bram:1.0 bias_PORTB DOUT";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of stub : architecture is "conv2d_layer,Vivado 2025.2";
begin
end;
