#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<cuda_runtime.h>
#include <windows.h>
#define N 10000000
#define BLOCK_SIZE 256

// CPU vector addition
void vector_add_cpu(float *a, float *b, float *c, int n){
    for(int i=0; i < n; i++){
        c[i] = a[i] + b[i];
    }
}

// CUDA kernel for vector addition
__global__ void vector_add_gpu(float* a, float* b, float* c , int n){
    int i = blockIdx.x * blockDim.x * threadIdx.x;
    if (i<n){
        c[i] = a[i] + b[i];
    }
}

// Initialize vector with random values
void init_vector(float *vec, int n){
    for(int i=0; i<n; i++){
        vec[i] = (float)rand() / RAND_MAX;
    }
}

// Function to measure execution time
double get_time(){
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);  // Get the frequency of the high-resolution timer
    QueryPerformanceCounter(&counter); // Get the current value of the counter
    return (double)counter.QuadPart / freq.QuadPart;
}

int main(){
    float *h_a, *h_b, *h_c_cpu, *h_c_gpu;
    float *d_a, *d_b, *d_c;
    size_t size = N * sizeof(float);

    // Allocate host memory;
    h_a = (float*)malloc(size);
    h_b = (float*)malloc(size);

    h_c_cpu = (float*)malloc(size);
    h_c_gpu = (float*)malloc(size);

    // Initialize vectors
    srand(time(NULL));
    init_vector(h_a, N);
    init_vector(h_b, N);

    // Allocate device memory
    cudaMalloc(&d_a, size);
    cudaMalloc(&d_b , size);
    cudaMalloc(&d_c , size);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);
    

    return 0;
}
