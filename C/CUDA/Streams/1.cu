#include<cuda_runtime.h>
#include<stdio.h>

#define CHECK_CUDA_ERROR(val) check((val), #val, __FILE__, __LINE__)

template <typename>

template<typename T>
void check(T err, const char* const func, const char* const file, const int line){
    if(err != cudaSuccess){
        fprintf(stderr, "CUDA error at %s:%d code=%d(%s)\%s\" \n", file, line, static_cast<unsigned int>(err), cudaGetErrorString(err), func);
        exit(EXIT_FAILURE);
    }
}

__global__ void vectorAdd(const float *A, const float *B, float *C, int numElements){
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < numElements){
        C[i] = A[i] + B[i];
    }
}

int main(){
    int numElements = 50000;
    size_t size = numElements * sizeof(float);
    float *h_A, *h_B, *h_C;
    float *d_A, *d_B, *d_C;
    cudaStream_t  stream1, stream2;

    //Allocate host memory
    h_A = (float*)malloc(size);
    h_B = (float*)malloc(size);
    h_C = (float*)malloc(size);

    // # Initialize host array
    for(int i=0; i<numElements; i++){
        h_A[i] = rand() / (float)RAND_MAX;
        h_B[i] = rand() / (float)RAND_MAX;
    };

    // Allocate device memory
    CHECK_CUDA_ERROR(cudaMalloc((void **)&d_A, size));
    CHECK_CUDA_ERROR(cudaMalloc((void **)&d_B, size));
    CHECK_CUDA_ERROR(cudaMalloc((void **)&d_C, size));

    // Create Stream
    CHECK_CUDA_ERROR(cudaStreamCreate(&stream1));
    CHECK_CUDA_ERROR(cudaStreamCreate(&stream2));

    //lAUNCHG KERNELS
    int threadsperBlock = 256;
    int blocksPerGrid = (numElements + threadsperBlock - 1);
    vectorAdd<<<blocksPerGrid, threadsperBlock>>>(d_A, d_B, d_C, numElements);
    
    // Copy result back to host asynchronously
    CHECK_CUDA_ERROR(cudaMemcpyAsync(h_C, d_C, size, cudaMemcpyDeviceToHost, stream1));

    // Synchronize streams
    CHECK_CUDA_ERROR()
    return 0;
}