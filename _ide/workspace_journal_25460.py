# 2026-02-20T11:06:48.019943200
import vitis

client = vitis.create_client()
client.set_workspace(path="D:/yolov5s_conv")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../pynqZ2.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

comp = client.create_app_component(name="app",platform = "$COMPONENT_LOCATION/../platform/export/platform/platform.xpfm",domain = "standalone_ps7_cortexa9_0")

platform = client.get_component(name="platform")
status = platform.build()

comp = client.get_component(name="app")
comp.build()

vitis.dispose()

