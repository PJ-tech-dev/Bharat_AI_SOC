# 2026-02-20T14:31:35.078757200
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis")

comp = client.get_component(name="cnn_app")
comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["# Add extra include paths set(USER_COMPILE_DEFINITIONS "")  set(USER_INCLUDE_DIRECTORIES ${USER_INCLUDE_DIRECTORIES} D:/yolov5s_conv/vitis/cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9 )"])

comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["D:/yolov5s_conv/vitis/cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9"])

comp = client.get_component(name="cnn_app")
status = comp.clean()

platform = client.get_component(name="cnn_platform")
status = platform.build()

comp.build()

status = platform.build()

comp.build()

comp = client.get_component(name="cnn_app")
comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["../../cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9", "D:/yolov5s_conv/vitis/cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9"])

status = platform.build()

comp = client.get_component(name="cnn_app")
comp.build()

comp = client.get_component(name="cnn_app")
comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["../../cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9", "D:/yolov5s_conv/vitis/cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9"])

status = platform.build()

comp = client.get_component(name="cnn_app")
comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../design_fixed.xsa")

status = platform.build()

status = comp.clean()

status = platform.build()

comp.build()

comp = client.get_component(name="cnn_app")
comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["../../cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9", "D:/yolov5s_conv/vitis/cnn_platform/ps7_cortexa9_0/standalone_ps7_cortexa9_0/bsp/libsrc/standalone/src/arm/cortexa9", "D:\yolov5s_conv\vitis\cnn_platform\ps7_cortexa9_0\standalone_ps7_cortexa9_0\bsp\include\xparameters.h"])

status = platform.build()

comp = client.get_component(name="cnn_app")
comp.build()

status = platform.build()

comp.build()

