OS=$(shell uname)
CUDA_HOME=/usr/local/cuda

ifeq ($(OS), Darwin)
	NO_NVML=1
endif

CXXFLAGS+=-I "$(CUDA_HOME)/include"

ifeq ($(OS), Darwin)
	CXXFLAGS+=-L "$(CUDA_HOME)/lib/"
else
	CXXFLAGS+=-L "$(CUDA_HOME)/lib64/"
endif

ifneq ($(NO_NVML), 1)
	NVIDIA_DRIVER_VERSION=$(shell cat /proc/driver/nvidia/version | sed -e 2d | sed -E 's,.* ([0-9]*)\.([0-9\.]*) .*,\1,')
	CXXFLAGS+=-L "/usr/lib/nvidia-$(NVIDIA_DRIVER_VERSION)/"
	LDFLAGS+=-lnvidia-ml
else
	CXXFLAGS+=-DNO_NVML=1
endif

gpu_util: gpu_util.cpp
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) -o $@

clean:
	$(RM) gpu_util
