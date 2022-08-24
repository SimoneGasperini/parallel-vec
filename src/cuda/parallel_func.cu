#include "../../include/parallel_func.h"

__global__ void parallel_add(int size, float *array1, float *array2, float *result)
{
	int index = threadIdx.x + blockIdx.x * blockDim.x;
	int stride = blockDim.x * gridDim.x;

	for (int i = index; i < size; i += stride)
		result[i] = array1[i] + array2[i];
}

__global__ void parallel_mul(int size, float *array1, float *array2, float *result)
{
	int index = threadIdx.x + blockIdx.x * blockDim.x;
	int stride = blockDim.x * gridDim.x;

	for (int i = index; i < size; i += stride)
		result[i] = array1[i] * array2[i];
}

__global__ void parallel_mul(int size, float *array, float scalar, float *result)
{
	int index = threadIdx.x + blockIdx.x * blockDim.x;
	int stride = blockDim.x * gridDim.x;

	for (int i = index; i < size; i += stride)
		result[i] = array[i] * scalar;
}