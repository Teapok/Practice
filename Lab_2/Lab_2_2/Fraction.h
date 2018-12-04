#pragma once

// Класс обычных дробей
class Fraction
{
// Переменные
private:
	int x;
	int y;
	static int c; // Количество дробей инициализированных в данный момент

// Конструкторы
public:
	Fraction(int x,int y);
	Fraction();
	~Fraction();

// Методы
public:
	void reduce(); // Сокращает дробь
	void getFraction(); // Выводит дробь
	
	// Статические методы
	static int gcd(int n, int m); // Функция нахождения наибольшего общего делителя
	static void printAsFraction(double decimal_fraction); // Перевод в обычную дробь из вещественного
	static void printAsFraction(char* decimal_fraction); // Перевод в обычную дробь из строки
	static void getCount(); // Выводит количество дробей инициализированных в данный момент

	// Перегрузки операторов
	friend const Fraction &operator+(Fraction &fr1,Fraction &fr2);
	friend const Fraction &operator-(Fraction &fr1, Fraction &fr2);
	friend const Fraction &operator*(Fraction &fr1, Fraction &fr2);
	friend const Fraction &operator/(Fraction &fr1, Fraction &fr2);
};

