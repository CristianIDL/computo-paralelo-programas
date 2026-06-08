#include <stdio.h>
#include <cuda_runtime.h>

__global__ void HolaDesdeGPU()
{
    printf("Hola Mundo desde GPU (device o dispositivo)!\n");
}

int main(void)
{
    printf("Hola Mundo desde CPU (host)!\n");

    HolaDesdeGPU<<<1,1000>>>();

    cudaDeviceSynchronize();

    return 0;
}