#include "../../include/serial_func.h"

float *serial_add(int size, float *array1, float *array2)
{
	float *sum = new float[size];
	for (int i = 0; i < size; i++)
		sum[i] = array1[i] + array2[i];

	return sum;
}

float *serial_mul(int size, float *array1, float *array2)
{
	float *prod = new float[size];
	for (int i = 0; i < size; i++)
		prod[i] = array1[i] * array2[i];

	return prod;
}

float *serial_mul(int size, float *array, float scalar)
{
	float *prod = new float[size];
	for (int i = 0; i < size; i++)
		prod[i] = array[i] * scalar;

	return prod;
}