#include "stdafx.h"
#include "Matrix.h"
#include <iostream>
#include <iomanip>

int  fact(int N)
{
	if (N < 0) // ���� ������������ ���� ������������� �����
		return 0; // ���������� ����
	if (N == 0) // ���� ������������ ���� ����,
		return 1; // ���������� ��������� �� ���� - ��� 1 =)
	else // �� ���� ��������� �������
		return N * fact(N - 1); // ������ ��������.
}

Matrix::Matrix(size_t r,size_t c)
{
	
	rows = r;
	columns = c;
	arr = new double*[rows];
	for (int i = 0; i < rows; i++) {
		*(arr + i) = new double[columns];


		for (int j = 0; j < columns; j++) {
			arr[i][j] = fact(i + j);
		}
	}

}


Matrix::Matrix(double** arr2D, size_t r, size_t c)
{
	rows = r;
	columns = c;
	arr = new double*[rows];
	for (int i = 0; i < rows; i++) {
		*(arr + i) = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			*(*(arr + i) + j) = *(*(arr2D + i) + j);
		}
	}
	
}


Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++) {
		delete arr[i];
	}
	delete arr;
}


void Matrix::ShowArray()
{
	std::cout << std::endl << "2D array" << std::endl << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
							std::cout << std::setw(14) << *(*(arr + i) + j);
			}
			std::cout << std::endl;
	}
}


double* Matrix::ConvertToArray1D()
{
	double* arr1D = new double[rows*columns];
	int y = 0;
	for (int i = 0; i < rows; i++) 
	{
		if (i % 2 != 0) {}
		else
		{
			for (int j = 0; j < columns; j++) {
				*(arr1D + y) = *(*(arr + i) + j);
				y++;
			}
		}
	}
	return arr1D;
	
	/*double* arr1D = new double[rows * columns]; // �������� ����������� ������������� �������
	int vector_counter = 0; // ����������-������ ��� ����������� �������

	for (int counter_rows = 0; counter_rows < rows; counter_rows++)
	{
		if (rows % 2 != 0) {}
		else
		{
			for (int counter_columns = 0; counter_columns < columns; counter_columns++)
			{
				//if (!isEven(counter_rows))//�������� ���
				arr1D[vector_counter] = arr[counter_rows][counter_columns];//���� ��� �� �� ���������� ������ ������
																			   //else {
																			   //vectorPtr[vector_counter] = ptrarray[counter_rows++][counter_columns];// ������������� ������ ���� ��������
																			   //counter_rows++;
																			   //}
				std::cout << arr1D[vector_counter] << "  "; // ������ ��������� ����������� �������
				vector_counter++; // ��������� �������
			}
			std::cout << "\n";
		}
	}
	return arr1D;*/
}


double Matrix::at(size_t r,size_t c) const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (r == i && c == j)
				return *(*(arr + i) + j);
		}
	}
	std::cout << "N/A." << std::endl;
	return NULL;
}


void Matrix::setAt(size_t r, size_t c, double val)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (r == i&&c==j) {
				*(*(arr + i) + j) = val;
				return;
			}
		}
	}
	std::cout << "N/A." << std::endl;
}


const Matrix &operator++(Matrix& i, int)
{
	Matrix oldValue(i.arr,i.rows,i.columns);
	for (int r = 0; r < i.rows; r++) {
		for (int c = 0; c < i.columns; c++) {
			*(*(i.arr + r) + c)+=1;
		}
	}
	return oldValue;
}


const Matrix& operator++(Matrix& i)
{
	for (int r = 0; r < i.rows; r++) {
		for (int c = 0; c < i.columns; c++) {
			*(*(i.arr + r) + c) += 1;
		}
	}
	return i;
}


const Matrix &operator--(Matrix& i, int)
{
	Matrix oldValue(i.arr, i.rows, i.columns);
	for (int r = 0; r < i.rows; r++) {
		for (int c = 0; c < i.columns; c++) {
			*(*(i.arr + r) + c) -= 1;
		}
	}
	return oldValue;
}


const Matrix& operator--(Matrix& i)
{
	for (int r = 0; r < i.rows; r++) {
		for (int c = 0; c < i.columns; c++) {
			*(*(i.arr + r) + c) -= 1;
		}
	}
	return i;
}



