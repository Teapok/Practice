#pragma once
class Vector
{
private: // Переменные
	double* arr;
	size_t lenght;

public: // Конструкторы
	Vector(size_t leng);
	Vector(double* arr1D,size_t leng);
	~Vector();

public: // Методы
	void ShowArray();

	// Перегрузки операторов
    const double operator[](int n);
	friend const Vector& operator++(Vector& i, int);
	friend const Vector& operator++(Vector& i);
	friend const Vector& operator--(Vector& i, int);
	friend const Vector& operator--(Vector& i);
};

