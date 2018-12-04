#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
	const size_t N = 5;
	const size_t M = 5;
	Matrix arr2D(N, M);
	arr2D.ShowArray();
	double* convert = arr2D.ConvertToArray1D();
	Vector arr1D(convert,15);
	std::cout << std::endl;
	arr1D.ShowArray();
	arr1D.operator[](12);

	int C1 = arr1D[-56];
	int C2 = arr1D[12];
	std::cout<<std::endl;
	std::cout << C1 << "\t" << C2 << "\t";

	//arr2D--;
	//std::cout << std::endl;
	//arr2D.ShowArray();
	//arr1D++;
	//std::cout << std::endl;
	//arr1D.ShowArray();

	//std::cout << std::endl;
	std::cout<<arr2D.at(4, 2)<<std::endl;
	std::cout << std::endl;
	arr2D.setAt(4, 2, 5);
	arr2D.ShowArray();

	std::cin.get();
	return 0;
}