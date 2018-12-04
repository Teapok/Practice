// Lab_2_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "stadion.h"

int main() {

	cf::Stadium * st1 = new cf::Stadium();
	cf::Stadium * st2 = new cf::Stadium();
	cf::Stadium st3(std::string("stadiumName3"), (size_t)10, (size_t)20000, std::string("nameFootballClub3"),std::string("adress3"));
st3.setAddress(std::string("adress2"));
std::string BB = st3.getAddress();
cf::Stadium * jopa = new cf::Stadium();
	delete st1;
	delete st2;
	std::cout << std::endl;
	system("pause");
	return 0;
}

