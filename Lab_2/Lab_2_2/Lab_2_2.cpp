// Lab_2_2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Fraction.h"
#include <iostream>

void getArrFraction(Fraction* fr, int count)
{
	for (int i = 0; i < count; i++) {
		Fraction temp(*(fr + i));

		std::cout << i + 1 << " fraction: ";
		temp.getFraction();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	bool alive = true;
	int i = 0;

	Fraction* fraction = new Fraction[20];

	while (alive) {
		int x;
		int y;
		std::cout << "Enter simple fraction: " << std::endl;
		std::cin >> x;
		std::cout << "/" << std::endl;
		std::cin >> y;

		if (y == 0) {
			if (x == 0) {
				getArrFraction(fraction, i);
				break;
			}
			else std::cout << "Cannot be divided by 0" << std::endl;
		}
		else {
			Fraction temp(x, y);
			*(fraction + i) = temp;
			i++;
			std::cout << "(Enter 0/0 for exit)" << std::endl;
			std::cout << std::endl;
		}
	}

	while (alive) {
		int fr1 = 0;
		int fr2 = 0;
		std::cout << "Operation" << std::endl;
		std::cout << "Enter number first fraction: ";
		std::cin >> fr1;

		if (fr1 != 0) {
			std::cout << "Enter number second fraction: ";
			std::cin >> fr2;
			std::cout << std::endl;
			Fraction fraction1 = *(fraction + fr1 - 1);
			Fraction fraction2 = *(fraction + fr2 - 1);
			Fraction add = fraction1 + fraction2;
			Fraction withdraw = fraction1 - fraction2;
			Fraction multi = fraction1 * fraction2;
			Fraction division = fraction1 / fraction2;

			fraction1.getFraction();
			std::cout << " + ";
			fraction2.getFraction();
			std::cout << " = ";
			add.getFraction();
			std::cout << std::endl;

			fraction1.getFraction();
			std::cout << " - ";
			fraction2.getFraction();
			std::cout << " = ";
			withdraw.getFraction();
			std::cout << std::endl;

			fraction1.getFraction();
			std::cout << " * ";
			fraction2.getFraction();
			std::cout << " = ";
			multi.getFraction();
			std::cout << std::endl;

			fraction1.getFraction();
			std::cout << " : ";
			fraction2.getFraction();
			std::cout << " = ";
			division.getFraction();
			std::cout << std::endl;

			std::cout << "(Enter number first fraction 0 for exit)" << std::endl;
			std::cout << std::endl;
		}
		else break;
	}

	std::cout << std::endl;
	std::cout << "Count: ";
	Fraction::getCount();

	std::cout << "235.15 In double: ";
	double d = 235.15;
	Fraction::printAsFraction(d);
	std::cout << std::endl;

	std::cout << "47.36 In char: ";
	char ch[13] = "47.36";
	Fraction::printAsFraction(ch);
	std::cout << std::endl;

	int n = 72;
	int m = 27;
	int mcd = Fraction::gcd(n, m);
	std::cout << "Max common divider " << n << " and " << m << " : ";
	std::cout << mcd << std::endl;

	std::cin.get();
	std::cin.get();
	return 0;
}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
