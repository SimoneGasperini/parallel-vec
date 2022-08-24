__global__ void parallel_add(int size, float *array1, float *array2, float *result);
__global__ void parallel_mul(int size, float *array1, float *array2, float *result);
__global__ void parallel_mul(int size, float *array, float scalar, float *result);