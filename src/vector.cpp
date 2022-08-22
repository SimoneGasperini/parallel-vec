#include <iostream>
#include "../hpp/vector.hpp"
#include "../include/serial_func.h"

Vector::Vector(int _size, float *_array)
{
	size = _size;
	array = new float[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = _array[i];
	}
}

Vector Vector::operator+(const Vector &that)
{
	try
	{
		if (size != that.size)
			throw "Vector Vector::operator+(const Vector &) -->\n\tThe vectors have different sizes\n";
	}
	catch (const char *err)
	{
		std::cout << "ERROR: " << err;
		throw;
	}

	float *array_sum = serial_add(size, array, that.array);
	Vector sum(size, array_sum);

	return sum;
}

float Vector::operator*(const Vector &that)
{
	try
	{
		if (size != that.size)
			throw "float Vector::operator*(const Vector &) -->\n\tThe vectors have different sizes\n";
	}
	catch (const char *err)
	{
		std::cout << "ERROR: " << err;
		throw;
	}

	float *array_prod = serial_mul(size, array, that.array);
	float dot = 0;
	for (int i = 0; i < size; i++)
	{
		dot += array_prod[i];
	}

	return dot;
}

Vector Vector::operator*(float scalar)
{
	float *array_prod = serial_mul(size, array, scalar);
	Vector prod(size, array_prod);

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