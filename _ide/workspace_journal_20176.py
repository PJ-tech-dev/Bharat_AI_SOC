# 2026-02-14T12:10:30.385134500
import vitis

client = vitis.create_client()
client.set_workspace(path="D:/yolov5s_conv")

advanced_options = client.create_advanced_options_dict(dt_overlay="0")

platform = client.create_platform_component(name = "platform",hw_design = "$COMPONENT_LOCATION/../design_1_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",generate_dtb = False,advanced_options = advanced_options,compiler = "gcc")

status = client.add_platform_repos(platform=["d:\yolov5s_conv"])

comp = client.create_app_component(name="cnn_app",platform = "$COMPONENT_LOCATION/../platform/export/platform/platform.xpfm",domain = "standalone_ps7_cortexa9_0")

vitis.dispose()

vitis.dispose()

