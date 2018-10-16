#include <cstdio>
#include <nvml.h>

int main(int argc, char* argv[])
{
    nvmlReturn_t result;
    unsigned int device_count;
    nvmlDevice_t device;
    nvmlUtilization_st device_utilization;

    result = nvmlInit();
    if (result != NVML_SUCCESS)
        return 1;
    
    result = nvmlDeviceGetCount(&device_count);
    if (result != NVML_SUCCESS)
        return 2;
    
    while (1) {
        for (int i = 0; i < 1; ++i) {            
            nvmlDeviceGetHandleByIndex(0, &device);            
            nvmlDeviceGetUtilizationRates(device, &device_utilization);
            std::printf("GPU Util: %u, Mem Util: %u\n", device_utilization.gpu, device_utilization.memory);
        }
    }
    nvmlShutdown();
    return 0;
}


/*
// original version
int main(int argc, char* argv[])
{
    nvmlReturn_t result;
    unsigned int device_count;

    result = nvmlInit();
    if (result != NVML_SUCCESS)
        return 1;
    
    result = nvmlDeviceGetCount(&device_count);
    if (result != NVML_SUCCESS)
        return 2;

    for (int i = 0; i < device_count; ++i) {
        nvmlDevice_t device;
        result = nvmlDeviceGetHandleByIndex(i, &device);
        if (result != NVML_SUCCESS)
            return 3;

        char device_name[NVML_DEVICE_NAME_BUFFER_SIZE];
        result = nvmlDeviceGetName(device, device_name, NVML_DEVICE_NAME_BUFFER_SIZE);
        if (result != NVML_SUCCESS)
            return 4;

        std::printf("Device %d: %s\n", i, device_name);

        nvmlUtilization_st device_utilization;
        result = nvmlDeviceGetUtilizationRates(device, &device_utilization);

        if (result != NVML_SUCCESS)
            return 5;

        std::printf("GPU Util: %u, Mem Util: %u\n", device_utilization.gpu, device_utilization.memory);
    }
    nvmlShutdown();
    return 0;
}*/