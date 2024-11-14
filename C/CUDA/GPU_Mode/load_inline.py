import torch
from torch.utils.cpp_extension import load_inline

# Define the cuda kernel and C++ wraper
cuda_source = '''
__global__ void square_matrix_kernel(const float* matrix, float* result, int width, int height){
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
}
'''