#include <iostream>
#include "../../hpp/vector.hpp"
#include "../../include/serial_func.h"

Vector::Vector(int _size, float *_array, bool _malloc)
{
	size = _size;

	if (_malloc)
	{
		array = new float[size];
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
	delete array;
}

Vector Vector::operator+(const Vector &that)
{
	float *array_sum = serial_add(size, array, that.array);
	Vector sum(size, array_sum);

	return sum;
}

float Vector::operator*(const Vector &that)
{
	float *array_prod = serial_mul(size, array, that.array);
	float dot = 0;
	for (int i = 0; i < size; i++)
		dot += array_prod[i];

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