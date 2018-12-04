#pragma once
class Vector
{
private: // ����������
	double* arr;
	size_t lenght;

public: // ������������
	Vector(size_t leng);
	Vector(double* arr1D,size_t leng);
	~Vector();

public: // ������
	void ShowArray();

	// ���������� ����������
    const double operator[](int n);
	friend const Vector& operator++(Vector& i, int);
	friend const Vector& operator++(Vector& i);
	friend const Vector& operator--(Vector& i, int);
	friend const Vector& operator--(Vector& i);
};

