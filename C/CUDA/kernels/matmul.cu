#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cuda_runtime.h>
#include<Windows.h>
#define M 256  // Number of rows in A and C
#define K 512   //  Number of columns in A and rows in B
#define N 256 // Number of columns in B and C
#define BLOCK_SIZE 32

/// Example 3x2 @ 2x4 = 3x4 --? (M X K) @ (K x N) = (M X N)
// A = [[1,2], 
//      [3,4],
//      [5,6]]

// B = [[7,8,9,10],
//     [11, 12 , 13 , 14]]

// C = [[29, 32 , 35, 38],
//     [65, 72, 79, 86],
//     [101, 112, 123, 134]]


// CPU matrix multitplication
void matmul_cpu(float *A, float *B, float *C, int m, int k, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            float sum = 0.0f;
            for(int l = 0; l<k; l++){
                sum+= A[i * k + l] * B[l * n +  j];
            }
            C[i * n + j] = sum;
        }
    }
}

/// Example 3x2 @ 2x4 = 3x4 --? (M X K) @ (K x N) = (M X N)

// CUDA kernel for matrix multiplication
__global__ void matmul_gpu(float *A, float *B, float *C, int m, int k, int n){
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < m && col < n){
        float sum = 0.0;
        for(int l = 0; l<k; l++){
            sum += A[row * k + l] * B[l * n + col];
        }
        C[row * n + col] = sum;
    }
}

void init_matrix(float *mat, int rows, int cols){
    for(int i=0; i<rows*cols; i++){
        mat[i] = (float)rand()/RAND_MAX;
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
    float *h_A, *h_B, *h_C_cpu, *h_C_gpu;
    float *d_A, *d_B, *d_C;
    int size_A = M * K * sizeof(float);
    int size_B = K * N * sizeof(float);
    int size_C = M * N * sizeof(float);

    // Allocate host memory
    h_A = (float*)(malloc)(size_A);
    h_B = (float*)(malloc)(size_B);
    h_C_cpu = (float*)(malloc)(size_C);
    h_C_gpu = (float*)malloc(size_C);
    // Allocate device memory

    cudaMalloc(&d_A, size_A);
    cudaMalloc(&d_B, size_B);
    cudaMalloc(&d_C, size_C);

    // Copy data to device
    cudaMemcpy(d_A, h_A, size_A, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size_B, cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 blockDim(BLOCK_SIZE, BLOCK_SIZE);
    dim3 gridDim((N + BLOCK_SIZE - 1)/BLOCK_SIZE, (M  + BLOCK_SIZE - 1)/ BLOCK_SIZE);
    printf("Performing warm-up runs....\n");
    for(int i=0; i<3; i++){
        matmul_cpu(h_A, h_B, h_C_cpu, M,K,N);
        matmul_gpu<<<gridDim, blockDim>>>(d_A, d_B,d_C, M, K , N);
        cudaDeviceSynchronize();
    }

        // Benchmark CPU implementation
    printf("Benchmarking CPU implementation...\n");
    double cpu_total_time = 0.0;
    for (int i = 0; i < 20; i++) {
        double start_time = get_time();
        matmul_cpu(h_A, h_B, h_C_cpu, M, K, N);
        double end_time = get_time();
        cpu_total_time += end_time - start_time;
    }
    double cpu_avg_time = cpu_total_time / 20.0;

    // Benchmark GPU implementation
    printf("Benchmarking GPU implementation...\n");
    double gpu_total_time = 0.0;
    for (int i = 0; i < 20; i++) {
        double start_time = get_time();
        matmul_gpu<<<gridDim, blockDim>>>(d_A, d_B, d_C, M, K, N);
        cudaDeviceSynchronize();
        double end_time = get_time();
        gpu_total_time += end_time - start_time;
    }
    double gpu_avg_time = gpu_total_time / 20.0;

    printf("CPU average time: %f microseconds\n", (cpu_avg_time * 1e6f));
    printf("GPU average time: %f microseconds\n", (gpu_avg_time * 1e6f));
    printf("Speedup: %fx\n", cpu_avg_time / gpu_avg_time);

    bool correct = true;
    for (int i = 0; i < M * N; i++) {
        if (fabs(h_C_cpu[i] - h_C_gpu[i]) > 1e-5) {
            correct = false;
            break;
        }
    }
    printf("Results are %s\n", correct ? "correct" : "incorrect");


    free(h_A);
    free(h_B);
    free(h_C_cpu);
    free(h_C_gpu);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);
    

    return 0;
}