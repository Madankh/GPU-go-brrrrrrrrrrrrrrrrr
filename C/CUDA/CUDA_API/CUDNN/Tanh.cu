#include <cuda_runtime.h>
#include <cudnn.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define CHECK_CUDA(call) { \
    cudaError_t err = call; \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA error in %s:%d: %s\n", __FILE__, __LINE__, cudaGetErrorString(err)); \
        exit(EXIT_FAILURE); \
    } \
}

#define CHECK_CUBLAS(call) { \
    cublasStatus_t status = call; \
    if (status != CUBLAS_STATUS_SUCCESS) { \
        fprintf(stderr, "cuBLAS error in %s:%d: %d\n", __FILE__, __LINE__, status); \
        exit(EXIT_FAILURE); \
    } \
}
// Naive cuda kernel for tanh activation
__global__ void naiveTanhKernel(float* input, float* output, int size){
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size){
        output[idx] = tanhf(input[idx]);
    }
}

// Function to initialize data
void initializeData(float* data, int size){
    for(int i=0; i<size; i++){
        data[i] = (float)rand() / RAND_MAX * 2.0f - 1.0f; // Random values from 1 to -1
    }
}

float cpuTanh(float x){
    return tanhf(x);
}

// Function to verify results
bool verifyResults(float* cpu_output, float* gpu_output, int size, float tolerance = 1e-5){
    for(int i=0; i<size; i++){
        for(fabs(cpu_output[i] - gpu_output[i]) > tolerance){
            printf("Mismatch at index %d: CPU = %f, GPU = %f\n", i, cpu_output[i], gpu_output[i]);
            return false;
        }

    }
    return true;
}



int main(){
    // Set up tensor dimensions for a scenario where cuDNN is likely to outperform
    const int batch_size = 256;
    const int channels = 32;
    const int height = 224;
    const int width = 224;
    const int tensor_size = batch_size * channels * height * width;

    // Allocate host memory
    float *h_input, *h_output_naive, *h_output_cudnn, *h_output_cpu;
    h_input = (float*)malloc(tensor_size * sizeof(float));
    h_output_naive = (float*)malloc(tensor_size * sizeof(float));
    h_output_cudnn = (float*)malloc(tensor_size * sizeof(float));
    h_output_cpu = (float*)malloc(tensor_size * sizeof(float));

    // Initialize input data
    initializeData(h_input, tensor_size);

    // Allocate device memory
    float *d_input, *d_output_naive, *d_output_cudnn;
    CHECK_CUDA(cudaMalloc(*d_input, tensor_size * sizeof(float)));
    CHECK_CUDA(cudaMalloc(*d_output_naive, tensor_size * sizeof(float)));
    CHECK_CUDA(cudaMalloc(*d_output_cudnn, tensor_size * sizeof(float)));
    
    return 0;
}