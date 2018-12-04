#include "stdafx.h"
#include "Vector.h"
#include <iostream>;

Vector::Vector(size_t len)
{
	lenght = len;
	arr = new double[lenght];
}


Vector::Vector(double* arr1D,size_t len)
{
	lenght = len;
	arr = new double[lenght];
	for (int i = 0; i < lenght; i++) {
		*(arr + i) = *(arr1D + i);
	}
}


Vector::~Vector()
{
	delete arr;
}


void Vector::ShowArray()
{
	std::cout << std::endl << "2D to 1D array" << std::endl << std::endl;
	std::cout << "[ ";
	for (int i = 0; i < lenght; i++) {
		std::cout << *(arr + i) << " ";
	}
	std::cout << "]" << std::endl;
}


const double Vector::operator[](int n)
{
	try 
	{
		if (n > lenght || n<0)
			throw 1;
		else
			for (int i = 0; i < lenght; i++)
				if (i == n)
					return *(arr + n);
	}
	catch (int numbError)
	{
		std::cout << std::endl;
		std::cout << "Error: Out of range array." << std::endl;
	}
	return NULL;
}


const Vector &operator++(Vector& i, int)
{
	Vector oldValue(i.arr, i.lenght);
	for (int l = 0; l < i.lenght; l++) {
		*(i.arr + l) += 1;
	}
	return oldValue;
}


const Vector& operator++(Vector& i)
{
	for (int l = 0; l < i.lenght; l++) {
		*(i.arr + l) += 1;
	}
	return i;
}


const Vector &operator--(Vector& i, int)
{
	Vector oldValue(i.arr, i.lenght);
	for (int l = 0; l < i.lenght; l++) {
		*(i.arr + l) -= 1;
	}
	return oldValue;
}


const Vector& operator--(Vector& i)
{
	for (int l = 0; l < i.lenght; l++) {
		*(i.arr + l) -= 1;
	}
	return i;
}