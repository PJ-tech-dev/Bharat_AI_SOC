# 2026-02-16T22:17:41.152580500
import vitis

client = vitis.create_client()
client.set_workspace(path="D:/yolov5s_conv")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="cnn_app")
comp.build()

comp = client.get_component(name="cnn_app")
comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["D:\yolov5s_conv\platform\export\platform\sw\standalone_ps7_cortexa9_0\include"])

comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["../../platform/export/platform/sw/standalone_ps7_cortexa9_0/include", "D:\yolov5s_conv\platform\export\platform\sw\standalone_ps7_cortexa9_0\bsp\ps7_cortexa9_0\include"])

comp.set_app_config(key = "USER_LINK_LIBRARIES", values = ["D:\yolov5s_conv\platform\export\platform\sw\standalone_ps7_cortexa9_0\lib"])

comp.set_app_config(key = "USER_LINK_LIBRARIES", values = [""])

comp.set_app_config(key = "USER_LINK_LIBRARIES", values = ["xil"])

comp.set_app_config(key = "USER_LINK_LIBRARIES", values = ["xil", "gcc"])

comp.set_app_config(key = "USER_LINK_LIBRARIES", values = ["xil", "gcc", "c"])

comp.set_app_config(key = "USER_LINK_LIBRARIES", values = ["xil", "gcc", "c", "m"])

comp.set_app_config(key = "USER_LINK_DIRECTORIES", values = ["D:\yolov5s_conv\platform\export\platform\sw\standalone_ps7_cortexa9_0\lib"])

comp.set_app_config(key = "USER_INCLUDE_DIRECTORIES", values = ["../../platform/export/platform/sw/standalone_ps7_cortexa9_0/include", "D:\yolov5s_conv\platform\ps7_cortexa9_0\standalone_ps7_cortexa9_0\bsp\include"])

comp = client.get_component(name="cnn_app")
status = comp.clean()

status = comp.clean()

status = comp.clean()

status = platform.build()

comp.build()

status = comp.clean()

status = platform.build()

comp.build()

status = comp.clean()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

vitis.dispose()

