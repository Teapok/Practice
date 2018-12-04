#pragma once
class Matrix
{
private: // Переменные
	double** arr;
	size_t rows;
	size_t columns;

public: // Конструкторы
	Matrix(size_t r, size_t c);
	Matrix(double** arr2D, size_t r, size_t c);
	~Matrix();

public: // Методы
	void ShowArray();
	double* ConvertToArray1D();
	double at(size_t r, size_t c) const;
	void setAt(size_t r, size_t c, double val);
	
	// Перегрузка операторов
	friend const Matrix& operator++(Matrix& i,int);
	friend const Matrix& operator++(Matrix& i);
	friend const Matrix& operator--(Matrix& i, int);
	friend const Matrix& operator--(Matrix& i);
};

