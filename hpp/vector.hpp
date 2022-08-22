#include <iostream>

class Vector
{
	int size;
	float *array;

public:
	Vector(int size, float *array);

	Vector operator+(const Vector &that);
	float operator*(const Vector &that);
	Vector operator*(float scalar);

	friend std::ostream &operator<<(std::ostream &os, Vector &v);
};