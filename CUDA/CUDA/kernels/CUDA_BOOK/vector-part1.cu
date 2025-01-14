#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cuda_runtime.h>
#define N 10000000
#define BLOCK_SIZE 250

void init_vector(float *vec, int n){
    for(int i=0; i<n; i++){
        vec[i] = (float)rand()/RAND_MAX;
    }
}

__global__ void vecAddcuda(float *d_A, float *d_B, float *d_C, int n){
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if(i<n){
        d_C[i] = d_A[i] + d_B[i];
    }
};

void vecAdd(float* A_h, float* B_h, float* C_h, int n){
    for(int i=0;  i<n; i++){
        C_h[i] = A_h[i] + B_h[i];
    }
}

int main(){
    float *h_A, *h_B, *h_C, *h_gpu_result;
    float *d_A, *d_B, *d_C;
    size_t size = N * sizeof(float);
    // Allocate host memory
    h_A = (float*)malloc(size);
    h_B = (float*)malloc(size);
    h_C = (float*)malloc(size);
    h_gpu_result = (float*)malloc(size);

    // Initialize vectors
    srand(time(NULL));
    init_vector(h_A, N);
    init_vector(h_B, N);

    // Allocate device memory
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_B, size);
    cudaMalloc((void**)&d_C, size);

    cudaMemcpy(d_A, h_A, size , cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size , cudaMemcpyHostToDevice);

    // Define grid and block diminestion
    int num_blocks = (N + BLOCK_SIZE - 1)/BLOCK_SIZE;

    // warm-up runs
    printf("Performing warm-up runs...\n");
    for(int i=0; i<3; i++){
        vecAdd(h_A, h_B, h_C, N);
    }

    printf("Performing CUDA warm-up runs...\n");
    for(int i=0; i<3; i++){
        vecAddcuda<<<num_blocks , BLOCK_SIZE>>>(d_A, d_B, d_C, N);
        cudaDeviceSynchronize();
    }
    cudaMemcpy(h_gpu_result, d_C, size, cudaMemcpyDeviceToHost);

    // vecAdd(A, B, C, N);
    bool correct = true;
    for(int i=0; i<N; i++){
        if (fabs(h_C[i] - h_gpu_result[i]) > 1e-5) {
            correct = false;
            break;
        }
    }
    printf("Results are %s\n", correct ? "correct" : "incorrect");
    free(h_A);
    free(h_B);
    free(h_C);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    cudaFree(h_gpu_result);
    return 0;


    return 0;
}