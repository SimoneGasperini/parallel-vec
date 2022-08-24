#include <iostream>
#include <ctime>
#include "./hpp/vector.hpp"

int main()
{
	int size = 8e7;
	float *array1 = new float[size];
	float *array2 = new float[size];
	for (int i = 0; i < size; i++)
	{
		array1[i] = 3.4;
		array2[i] = 5.1;
	}

	Vector vector1(size, array1);
	Vector vector2(size, array2);

	clock_t t1 = clock();
	Vector sum = vector1 + vector2;
	clock_t t2 = clock();
	std::cout << "Sum 2 Vector objects of size = " << size << "\n";
	std::cout << "--> elapsed time = " << double(t2 - t1) / CLOCKS_PER_SEC << "\n";

	vector1.free();
	vector2.free();
	sum.free();

	return 0;
}