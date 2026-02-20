# 2026-02-20T12:49:43.659082800
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis")

platform = client.create_platform_component(name = "cnn_platform",hw_design = "$COMPONENT_LOCATION/../../design_1_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

comp = client.create_app_component(name="cnn_app",platform = "$COMPONENT_LOCATION/../cnn_platform/export/cnn_platform/cnn_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

comp = client.get_component(name="cnn_app")
status = comp.clean()

platform = client.get_component(name="cnn_platform")
status = platform.build()

status = platform.build()

comp.build()

client.delete_component(name="cnn_platform")

client.delete_component(name="cnn_platform")

client.delete_component(name="cnn_app")

client.delete_component(name="componentName")

platform = client.create_platform_component(name = "cnn_platform",hw_design = "$COMPONENT_LOCATION/../design_fixed.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

comp = client.create_app_component(name="cnn_app",platform = "$COMPONENT_LOCATION/../cnn_platform/export/cnn_platform/cnn_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

vitis.dispose()

