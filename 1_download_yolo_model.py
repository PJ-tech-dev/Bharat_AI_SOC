# 1_download_yolo_model.py
import sys
import time
import urllib.request

import cv2
import numpy as np
from ultralytics import YOLO

print("=" * 60)
print("YOLO Model Download & Setup")
print("=" * 60)

# Step 1: Verify core dependencies
print("\n[1/4] Checking dependencies...")
print("OK Core dependencies are available (ultralytics, cv2, numpy)")

# Step 2: Load pre-trained YOLO model (yolov8n)
print("\n[2/4] Loading pre-trained YOLO model...")
try:
    model = YOLO("yolov8n.pt")
except Exception as e:
    print(f"ERROR failed to load model weights: {e}")
    print("Hint: check internet access and try again.")
    sys.exit(1)
print("OK YOLO model loaded (yolov8n.pt)")

# Step 3: Download a test image (COCO example)
print("\n[3/4] Downloading test image...")
test_image_url = "https://ultralytics.com/images/zidane.jpg"
try:
    urllib.request.urlretrieve(test_image_url, "test_image.jpg")
except Exception as e:
    print(f"ERROR failed to download test image: {e}")
    print("Hint: check internet access and try again.")
    sys.exit(1)
print("OK Test image downloaded (zidane.jpg)")

# Step 4: Run inference on test image
print("\n[4/4] Running inference on test image...")
try:
    results = model.predict(source="test_image.jpg", imgsz=640, verbose=False)
except Exception as e:
    print(f"ERROR inference failed: {e}")
    sys.exit(1)

# Display results
result = results[0]
print("\n" + "=" * 60)
print("INFERENCE RESULTS")
print("=" * 60)
detections = int(result.boxes.shape[0]) if result.boxes is not None else 0
print(f"Detections found: {detections}")
print("\nDetected objects:")

if detections == 0:
    print("  None")
else:
    for i, box in enumerate(result.boxes):
        cls = int(box.cls[0].item())
        conf = float(box.conf[0].item())
        class_name = result.names[cls]
        print(f"  {i + 1}. {class_name:15s} - Confidence: {conf:.2%}")

# Save result image
try:
    saved = result.save(filename="result.jpg")
    print("\nOK Result image saved to 'result.jpg'")
except Exception as e:
    print(f"WARNING could not save result image: {e}")

print("=" * 60)

# Test inference speed
print("\nPerformance Test (10 inferences):")
start = time.time()
for _ in range(10):
    _ = model.predict(source="test_image.jpg", imgsz=640, verbose=False)
elapsed = time.time() - start
avg_time = elapsed / 10 * 1000  # Convert to ms
print(f"  Average inference time: {avg_time:.1f} ms")
print(f"  FPS: {1000 / avg_time:.1f}")
print("=" * 60)
