import argparse
import os
import time

import numpy as np
import torch


TITLE = "YOLOv5s CPU Performance Baseline"
SEPARATOR = "=" * 60


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=TITLE)
    parser.add_argument("--runs", type=int, default=20, help="Number of benchmark runs")
    parser.add_argument("--warmup", type=int, default=5, help="Number of warmup runs")
    parser.add_argument("--size", type=int, default=640, help="Square input size")
    parser.add_argument("--threads", type=int, default=max(1, os.cpu_count() or 1), help="Torch CPU threads")
    parser.add_argument("--model", default="yolov5s", help="YOLOv5 model variant")
    parser.add_argument("--half", action="store_true", help="Try FP16 inference (may help on some CPUs)")
    return parser.parse_args()


def format_stats(latencies_ms: np.ndarray) -> dict[str, float]:
    avg = float(latencies_ms.mean())
    return {
        "min": float(latencies_ms.min()),
        "max": float(latencies_ms.max()),
        "avg": avg,
        "median": float(np.median(latencies_ms)),
        "std": float(latencies_ms.std()),
        "fps": 1000.0 / avg,
        "target_fpga_ms": avg / 2.0,
    }


def main() -> None:
    args = parse_args()

    print(SEPARATOR)
    print(TITLE)
    print(SEPARATOR)

    torch.set_num_threads(args.threads)

    print("\nLoading YOLOv5 model...")
    model = torch.hub.load("ultralytics/yolov5", args.model, pretrained=True)
    model.cpu().eval()

    use_half = False
    if args.half:
        try:
            model.half()
            use_half = True
        except Exception:
            # Some CPU backends/ops do not support FP16 efficiently.
            model.float()

    print(f"OK Model loaded: {args.model} on CPU")
    print(f"Torch threads: {torch.get_num_threads()}")
    print(f"FP16 enabled: {use_half}")

    print(f"\nGenerating test image ({args.size}x{args.size})...")
    rng = np.random.default_rng(42)
    dummy_image = rng.integers(0, 255, (args.size, args.size, 3), dtype=np.uint8)

    print(f"Warming up ({args.warmup} runs)...")
    with torch.inference_mode():
        for _ in range(args.warmup):
            _ = model(dummy_image)

    print(f"\nBenchmarking {args.runs} inferences...")
    latencies = np.empty(args.runs, dtype=np.float64)

    with torch.inference_mode():
        for i in range(args.runs):
            start = time.perf_counter()
            _ = model(dummy_image)
            elapsed_ms = (time.perf_counter() - start) * 1000.0
            latencies[i] = elapsed_ms

            if (i + 1) % 5 == 0 or i == args.runs - 1:
                print(f"  Run {i + 1}/{args.runs}: {elapsed_ms:.1f} ms")

    stats = format_stats(latencies)

    print("\n" + SEPARATOR)
    print("CPU BASELINE RESULTS")
    print(SEPARATOR)
    print(f"Minimum latency:  {stats['min']:.2f} ms")
    print(f"Maximum latency:  {stats['max']:.2f} ms")
    print(f"Average latency:  {stats['avg']:.2f} ms")
    print(f"Median latency:   {stats['median']:.2f} ms")
    print(f"Std deviation:    {stats['std']:.2f} ms")
    print(f"\nThroughput: {stats['fps']:.1f} FPS")
    print(SEPARATOR)

    print("\nThis is your CPU baseline for comparison with FPGA!")
    print("Target: FPGA should achieve 2x speedup")
    print(f"Target FPGA latency: {stats['target_fpga_ms']:.2f} ms")
    print(SEPARATOR)

    with open("cpu_baseline.txt", "w", encoding="utf-8") as f:
        f.write("CPU Baseline Results\n")
        f.write(f"Model: {args.model}\n")
        f.write(f"Runs: {args.runs}\n")
        f.write(f"Warmup: {args.warmup}\n")
        f.write(f"Threads: {torch.get_num_threads()}\n")
        f.write(f"FP16 enabled: {use_half}\n")
        f.write(f"Average latency: {stats['avg']:.2f} ms\n")
        f.write(f"Throughput: {stats['fps']:.1f} FPS\n")
        f.write("Target FPGA speedup: 2x\n")
        f.write(f"Target FPGA latency: {stats['target_fpga_ms']:.2f} ms\n")

    print("OK Results saved to 'cpu_baseline.txt'")


if __name__ == "__main__":
    main()
