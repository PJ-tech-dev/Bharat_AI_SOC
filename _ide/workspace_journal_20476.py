# 2026-02-18T11:04:51.998336
import vitis

client = vitis.create_client()
client.set_workspace(path="D:/yolov5s_conv")

comp = client.create_app_component(name="cnn_app",platform = "$COMPONENT_LOCATION/../cnn_platform/export/cnn_platform/cnn_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="cnn_app")
status = comp.clean()

platform = client.get_component(name="cnn_platform")
status = platform.build()

comp.build()

status = platform.build()

comp.build()

vitis.dispose()

