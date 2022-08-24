#include <iostream>
#include "../../hpp/vector.hpp"
#include "../../include/parallel_func.h"

Vector::Vector(int _size, float *_array, bool _malloc)
{
	size = _size;

	if (_malloc)
	{
		cudaMalloc(&array, size * sizeof(float));
		for (int i = 0; i < size; i++)
			array[i] = _array[i];
	}
	else
	{
		array = _array;
	}
}

void Vector::free()
{
	cudaFree(array);
}

Vector Vector::operator+(const Vector &that)
{
	float *result;
	cudaMalloc(&result, size * sizeof(float));

	int threadsPerBlock = 256;
	int numberOfBlocks = (size + threadsPerBlock - 1) / threadsPerBlock;
	parallel_add<<<numberOfBlocks, threadsPerBlock>>>(size, array, that.array, result);
	cudaDeviceSynchronize();

	Vector sum(size, result, false);

	return sum;
}

float Vector::operator*(const Vector &that)
{
	float *result;
	cudaMalloc(&result, size * sizeof(float));

	int threadsPerBlock = 256;
	int numberOfBlocks = (size + threadsPerBlock - 1) / threadsPerBlock;
	parallel_mul<<<numberOfBlocks, threadsPerBlock>>>(size, array, that.array, result);
	cudaDeviceSynchronize();

	float dot = 0;
	for (int i = 0; i < size; i++)
		dot += result[i];

	return dot;
}

Vector Vector::operator*(float scalar)
{
	float *result;
	cudaMalloc(&result, size * sizeof(float));

	int threadsPerBlock = 256;
	int numberOfBlocks = (size + threadsPerBlock - 1) / threadsPerBlock;
	parallel_mul<<<numberOfBlocks, threadsPerBlock>>>(size, array, scalar, result);
	cudaDeviceSynchronize();

	Vector prod(size, result, false);

	return prod;
}

std::ostream &operator<<(std::ostream &os, Vector &v)
{
	os << "[";
	for (int i = 0; i < v.size; i++)
	{
		os << v.array[i];
		if (i != v.size - 1)
			os << "  ";
	}
	os << "]";

	return os;
}