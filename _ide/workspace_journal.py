# 2026-02-20T11:22:33.548400300
import vitis

client = vitis.create_client()
client.set_workspace(path="D:/yolov5s_conv")

comp = client.get_component(name="app")
status = comp.clean()

platform = client.get_component(name="platform")
status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../pynqZ2.xsa")

status = platform.build()

status = platform.build()

status = comp.clean()

status = platform.build()

comp.build()

vitis.dispose()

