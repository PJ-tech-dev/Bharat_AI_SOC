# 3_quantize_to_int8.py
import torch
import torch.quantization as quantization
import time

print("=" * 60)
print("YOLOv5s Quantization to INT8")
print("=" * 60)

# Load model
print("\n[1/3] Loading YOLOv5s model...")
model = torch.hub.load('ultralytics/yolov5', 'yolov5s', pretrained=True)
model.eval()
print("✓ Model loaded")

# Prepare for quantization
print("\n[2/3] Preparing quantization...")
# Set quantization config
model.qconfig = quantization.get_default_qconfig('fbgemm')
quantization.prepare(model, inplace=True)

# Calibrate on sample data (normally use real COCO images)
print("  Calibrating on sample image...")
dummy_input = torch.randn(1, 3, 640, 640)
with torch.no_grad():
    _ = model(dummy_input)

# Convert to quantized model
print("\n[3/3] Converting to INT8...")
quantization.convert(model, inplace=True)
print("✓ Quantization complete")

# Save quantized model
print("\nSaving quantized model...")
torch.jit.save(torch.jit.script(model), 'yolov5s_quantized.pt')
print("✓ Saved as 'yolov5s_quantized.pt'")

# Compare sizes
import os
original_size = os.path.getsize('yolov5s.pt') if os.path.exists('yolov5s.pt') else 0
quantized_size = os.path.getsize('yolov5s_quantized.pt')

print("\n" + "=" * 60)
print("QUANTIZATION RESULTS")
print("=" * 60)
if original_size > 0:
    compression = (1 - quantized_size/original_size) * 100
    print(f"Original model: {original_size/1e6:.1f} MB")
    print(f"Quantized model: {quantized_size/1e6:.1f} MB")
    print(f"Compression: {compression:.1f}%")
else:
    print(f"Quantized model size: {quantized_size/1e6:.1f} MB")

print("\n✓ Model ready for FPGA deployment")
print("=" * 60)