<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda_runtime.h>
#include <windows.h>
#include <math.h>

=======
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<cuda_runtime.h>
#include <windows.h>
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
#define N 10000000
#define BLOCK_SIZE 256

// CPU vector addition
<<<<<<< HEAD
void vector_add_cpu(float *a, float *b, float *c, int n) {
    for (int i = 0; i < n; i++) {
=======
void vector_add_cpu(float *a, float *b, float *c, int n){
    for(int i=0; i < n; i++){
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
        c[i] = a[i] + b[i];
    }
}

// CUDA kernel for vector addition
<<<<<<< HEAD
__global__ void vector_add_gpu(float* a, float* b, float* c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
=======
__global__ void vector_add_gpu(float* a, float* b, float* c , int n){
    int i = blockIdx.x * blockDim.x * threadIdx.x;
    if (i<n){
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
        c[i] = a[i] + b[i];
    }
}

// Initialize vector with random values
<<<<<<< HEAD
void init_vector(float *vec, int n) {
    for (int i = 0; i < n; i++) {
=======
void init_vector(float *vec, int n){
    for(int i=0; i<n; i++){
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
        vec[i] = (float)rand() / RAND_MAX;
    }
}

// Function to measure execution time
<<<<<<< HEAD
double get_time() {
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&counter);
    return (double)(counter.QuadPart * 1000) / freq.QuadPart;
}

int main() {
=======
double get_time(){
    LARGE_INTEGER freq, counter;
    QueryPerformanceFrequency(&freq);  // Get the frequency of the high-resolution timer
    QueryPerformanceCounter(&counter); // Get the current value of the counter
    return (double)counter.QuadPart / freq.QuadPart;
}

int main(){
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
    float *h_a, *h_b, *h_c_cpu, *h_c_gpu;
    float *d_a, *d_b, *d_c;
    size_t size = N * sizeof(float);

<<<<<<< HEAD
    // Allocate host memory
    h_a = (float*)malloc(size);
    h_b = (float*)malloc(size);
=======
    // Allocate host memory;
    h_a = (float*)malloc(size);
    h_b = (float*)malloc(size);

>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
    h_c_cpu = (float*)malloc(size);
    h_c_gpu = (float*)malloc(size);

    // Initialize vectors
<<<<<<< HEAD
    srand((unsigned int)time(NULL));
=======
    srand(time(NULL));
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
    init_vector(h_a, N);
    init_vector(h_b, N);

    // Allocate device memory
    cudaMalloc(&d_a, size);
<<<<<<< HEAD
    cudaMalloc(&d_b, size);
    cudaMalloc(&d_c, size);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);

    int num_blocks = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;

    // Warm up runs
    printf("Performing warm-up runs...\n");
    for (int i = 0; i < 3; i++) {
        vector_add_cpu(h_a, h_b, h_c_cpu, N);
        vector_add_gpu<<<num_blocks, BLOCK_SIZE>>>(d_a, d_b, d_c, N);
        cudaDeviceSynchronize();
    }

    // Benchmark CPU implementation
    printf("Benchmarking CPU implementation...\n");
    double cpu_total_time = 0.0;
    for (int i = 0; i < 20; i++) {
        double start_time = get_time();
        vector_add_cpu(h_a, h_b, h_c_cpu, N);
        double end_time = get_time();
        cpu_total_time += end_time - start_time;
    }
    double cpu_avg_time = cpu_total_time / 20.0;

    // Benchmark GPU implementation
    printf("Benchmarking GPU implementation...\n");
    double gpu_total_time = 0.0;
    for (int i = 0; i < 20; i++) {
        double start_time = get_time();
        vector_add_gpu<<<num_blocks, BLOCK_SIZE>>>(d_a, d_b, d_c, N);
        cudaDeviceSynchronize();
        double end_time = get_time();
        gpu_total_time += end_time - start_time;
    }
    double gpu_avg_time = gpu_total_time / 20.0;

    // Print results
    printf("CPU average time: %f milliseconds\n", cpu_avg_time);
    printf("GPU average time: %f milliseconds\n", gpu_avg_time);
    printf("Speedup: %f\n", cpu_avg_time / gpu_avg_time);

    // Verify results
    cudaMemcpy(h_c_gpu, d_c, size, cudaMemcpyDeviceToHost);
    bool correct = true;
    for (int i = 0; i < N; i++) {
        if (fabs(h_c_cpu[i] - h_c_gpu[i]) > 1e-5) {
            correct = false;
            break;
        }
    }
    printf("Results are %s\n", correct ? "correct" : "incorrect");

    // Free memory
    free(h_a);
    free(h_b);
    free(h_c_cpu);
    free(h_c_gpu);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
=======
    cudaMalloc(&d_b , size);
    cudaMalloc(&d_c , size);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);
    

    return 0;
}
>>>>>>> 22bf1c6a42b3f9ef1f242423df72d0b85cad005f
