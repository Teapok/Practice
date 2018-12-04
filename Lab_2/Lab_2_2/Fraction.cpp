#include "stdafx.h"
#include "Fraction.h"
#include <iostream>


int Fraction::c = 0;

Fraction::Fraction(int x1,int y1)
{
	x = x1;
	y = y1;
	c++;
}


Fraction::Fraction()
{
}



Fraction::~Fraction()
{
}


void Fraction::reduce()
{
	int i = 2;
	while (i != 1) {
		i = Fraction::gcd(x, y);
		x /= i;
		y /= i;
	}
}


void Fraction::getFraction()
{
	std::cout << x << "/" << y;
}


void Fraction::getCount()
{
	std::cout << c << std::endl;
}


int Fraction::gcd(int n,int m)
{
	int min;
	if (n > m) min = abs(m);
	else min = abs(n);

	for (int i = min; i >= 2; i--) {
		if (n%i == 0 && m%i == 0) {
			return i;
		}
	}
	return 1;
}


void Fraction::printAsFraction(double decimal_fraction)
{
	int x;
	int y;
	x = (int)(decimal_fraction*100);
	y = 100;
	Fraction fraction(x, y);
	c--;
	fraction.reduce();
	fraction.getFraction();
}


void Fraction::printAsFraction(char* decimal_fraction)
{
	double d;
	int i = 0;
	int left;
	int right;
	char* temp_left=new char[10];
	char* temp_right=new char[2];

	// Перевод целой части числа из строки
	do {
		 *(temp_left + i)= *(decimal_fraction + i);
		i++;
	} 
	while (*(decimal_fraction + i) != '.');
	left = atoi(temp_left);

	// Перевод дробной части числа до 2 цифр после запятой из строки
	for (int j = 1; j <= 2; j++) {
		*(temp_right+j-1)=*(decimal_fraction + i + j);
	}
	right = atoi(temp_right);

	d = left + (right / 100.0);

	printAsFraction(d);
	delete(temp_left);
	delete(temp_right);
}


const Fraction &operator+(Fraction &fr1,Fraction &fr2)
{
	int x1 = fr1.x;
	int y1 = fr1.y;
	int x2 = fr2.x;
	int y2 = fr2.y;

	// Приведение дробей к одному знаменателю
	x1 *= y2;
	x2 *= y1;
	y1 *= y2;
	y2 = y1;

	Fraction temp(x1 + x2, y1);
	Fraction::c--;
	temp.reduce();
	return temp;
}


const Fraction &operator-(Fraction &fr1, Fraction &fr2)
{
	int x1 = fr1.x;
	int y1 = fr1.y;
	int x2 = fr2.x;
	int y2 = fr2.y;

	// Приведение дробей к одному знаменателю
	x1 *= y2;
	x2 *= y1;
	y1 *= y2;
	y2 = y1;

	Fraction temp(x1 - x2, y1);
	Fraction::c--;
	temp.reduce();
	return temp;
}


const Fraction &operator*(Fraction &fr1, Fraction &fr2)
{
	int x1 = fr1.x;
	int y1 = fr1.y;
	int x2 = fr2.x;
	int y2 = fr2.y;

	Fraction temp(x1 * x2, y1 * y2);
	Fraction::c--;
	temp.reduce();
	return temp;
}


const Fraction &operator/(Fraction &fr1, Fraction &fr2)
{
	Fraction fr2_revers(fr2.y, fr2.x);
	Fraction temp = fr1 * fr2_revers;
	Fraction::c--;
	temp.reduce();
	return temp;
}