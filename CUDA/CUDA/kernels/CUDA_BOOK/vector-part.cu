#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cuda_runtime.h>
#define N 100000000 // vector SIZE = 10 Millions
#define BLOCK_SIZE 256

void vecAdd(float* A_h, float* B_h, float* C_h, int n){
    for(int i=0;  i<n; i++){
        C_h[i] = A_h[i] + B_h[i];
    }
}
__global__ void vecAddCu(float* A_h, float* B_h , float *C_h, int n){
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if(i<n){
       C_h[i] = A_h[i] + B_h[i];
    }
}
void init_vector(float* vec , int n){
    for(int i=0; i<n; i++){
        vec[i] = (float)rand() / RAND_MAX;
    }
}

int main(){
    float *h_A, *h_B, *h_C, *h_C_gpu;
    size_t size = N * sizeof(float);
    
    // Allocate host memory
    h_A = (float*)malloc(size);
    h_B = (float*)malloc(size);
    h_C = (float*)malloc(size);
    h_C_gpu = (float*)malloc(size);

    // Initialize vectors
    srand(time(NULL));
    init_vector(h_A, N);
    init_vector(h_B, N);

    float *d_A, *d_B, *d_C;
    // allocate device mem
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);

    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Define grid and  block diminestion
    int num_blocks = (N + BLOCK_SIZE - 1)/BLOCK_SIZE;

    // warm-up runs
    printf("Performing warm-up runs...\n");
    for(int i=0; i<3; i++){
        vecAdd(h_A, h_B, h_C, N);
    }

    printf("Performing CUDA warm-up runs...\n");
    for(int i=0; i<3; i++){
        vecAddCu<<<num_blocks, BLOCK_SIZE>>>(d_A, d_B, d_C, N);
        cudaDeviceSynchronize();
    }
    cudaMemcpy(h_C_gpu, d_C, size, cudaMemcpyDeviceToHost);

    // vecAdd(A, B, C, N);
    bool correct = true;
    for(int i=0; i<3; i++){
        if (fabs(h_C[i] - h_C_gpu[i]) > 1e-5) {
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
    return 0;
}