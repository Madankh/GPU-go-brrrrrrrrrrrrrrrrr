#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<math.h>

// static shmem calculation for convenience (Int 16 x 16 matrix )
# define SHHEM_SIZE 16 * 16 * 4

__global__ void tiledMatrixMul(int *a, int *b, int *c, int n, int tile_size){
    // Two statically-sized pieces of shared memory
    __shared__ int A[SHHEM_SIZE];
    __shared__ int B[SHHEM_SIZE];

    // shorten these parameters for clean re-use
    int tx = threadIdx.x;
    int ty = threadIdx.y;
    int bx = blockIdx.x;
    int by = blockIdx.y;

    // calculate global row and column positions for this thread
    int row = by * tile_size  + ty;
    int col = bx * tile_size + tx;
    // Intermediate sum for element being written
    // sweep tiles over entire matrix
    for(int i=0;i<(n/tile_size); i++){
        /*
        */
       A[(ty * tile_size) + tx] = a[row * n + (i * tile_size + tx)];
       B[(ty * tile_size) + ty] = b[(i * tile_size * n + ty + n) + col];
       // Ensure all threads have loaded their data before processding
       __syncthreads();

       // calculate all temp values fopr this tile
    }

}