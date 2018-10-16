# GPU_Util

This is a tool to query GPU utilization rate on Linux platform. NVML is required to run this code. From CUDA 8.0, NVML is to be installed as a part of CUDA.

# Usage

```bash
$ make
$ ./gpu_util
```

# Additions

In some cases, the ***PATH*** to nvml.h or libnvidia-ml.so may be different. So, some modifications are needed.

# Reference

[sakamoto-poteko/nvml.cpp](https://gist.github.com/sakamoto-poteko/44d6cd19552fa7721b99)