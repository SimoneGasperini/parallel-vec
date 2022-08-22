#include <iostream>
#include "./hpp/vector.hpp"

int main()
{
	int size = 4;
	float array1[] = {2, 3, 1, 1};
	float array2[] = {1, 2, 3, 5};

	Vector vector1(size, array1);
	Vector vector2(size, array2);
	Vector sum = vector1 + vector2;
	float dot = vector1 * vector2;
	Vector prod = vector1 * 3;

	std::cout << "sum = " << sum;			  // sum = [3  5  4  6]
	std::cout << "\ndot = " << dot;			  // dot = 16
	std::cout << "\nprod = " << prod << "\n"; // prod = [6  9  3  3]

	return 0;
}