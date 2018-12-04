#include "stdafx.h" 
#include <cstdio> 
#include <iostream> 



// первое действие 

using namespace std;


int processArray(int arr[], size_t n) {
	for (size_t i = 0; i <= n; ++i) // заполнение массива случ. числами [20..100] 
	{
		arr[i] = 20 + rand() % 80;
	}printf("\n A= ");
	for (size_t i = 0; i < n; i++)
		printf("%d ", arr[i]);

	int b[15] = { 0 };
	int min = arr[0];
	for (int i = 0; i < 15; i++) //нахождение минимального 
	{
		b[i] = arr[i];
		if (arr[i] < min) {
			min = arr[i];
		}
	} printf("\n min=%d", min); //вывод минимального 

	for (int i = 0; i < 15; ++i) // вычитание min из всех элементов 
	{
		arr[i] = arr[i] - min;
	}printf("\n (A-min)= ");
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}printf("\n b= ");
	for (int i = 0; i < 15; ++i) {
		if (b[i] == min)
		{
			for (int i = 0; i < 15; ++i) {
				b[i] = min;
			}
		}printf("%d ", b[i]);
	}
	return 0; // возвращаем среднее 
}
int main()
{
	// размер массива равен 15 (по заданию) 
	const size_t n = 15;
	int a[n]; // создаем массив 
			  //инициализация генератора случайных чисел 
	srand(0);
	// подсчет min значения в массиве а, изменение массива b 
	processArray(a, n);
	cin.get();
	return 0;
}