# 2026-02-18T10:48:33.669715600
import vitis

client = vitis.create_client()
client.set_workspace(path="D:/yolov5s_conv")

platform = client.create_platform_component(name = "cnn_platform",hw_design = "$COMPONENT_LOCATION/../design_1_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

vitis.dispose()

