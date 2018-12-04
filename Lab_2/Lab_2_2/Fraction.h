#pragma once

// ����� ������� ������
class Fraction
{
// ����������
private:
	int x;
	int y;
	static int c; // ���������� ������ ������������������ � ������ ������

// ������������
public:
	Fraction(int x,int y);
	Fraction();
	~Fraction();

// ������
public:
	void reduce(); // ��������� �����
	void getFraction(); // ������� �����
	
	// ����������� ������
	static int gcd(int n, int m); // ������� ���������� ����������� ������ ��������
	static void printAsFraction(double decimal_fraction); // ������� � ������� ����� �� �������������
	static void printAsFraction(char* decimal_fraction); // ������� � ������� ����� �� ������
	static void getCount(); // ������� ���������� ������ ������������������ � ������ ������

	// ���������� ����������
	friend const Fraction &operator+(Fraction &fr1,Fraction &fr2);
	friend const Fraction &operator-(Fraction &fr1, Fraction &fr2);
	friend const Fraction &operator*(Fraction &fr1, Fraction &fr2);
	friend const Fraction &operator/(Fraction &fr1, Fraction &fr2);
};

