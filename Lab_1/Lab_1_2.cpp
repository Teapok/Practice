// Lab_1_1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int i){      //проверка на чет
    return (i % 2 == 0);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int number_rows=5,      // строки
number_columns=5;       // столбцы
int transformArray(int**),
print2D_Array(int**);
//-----------------------------------------------------------------------------------------------------------------------------------
long int fact(int N)    //факториал
{
    if(N < 0) // если отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если ноль,
        return 1; // возвращаем факториал от нуля - это 1 =)
    else // Во всех остальных случаях
        return N * fact(N - 1); // делаем рекурсию.
}
//-----------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------
int transformArray(int** ptrarray){
    cout << endl << "2D to 1D array" << endl << endl;
    int *vectorPtr = new int [number_rows * number_columns]; // создание одномерного динамического массива
    int vector_counter = 0; // переменная-индекс для одномерного массива

    for (int counter_rows = 0; counter_rows < number_rows; counter_rows++)
    {
        if(!isEven(counter_rows)){

        }else
        {
            for (int counter_columns = 0; counter_columns < number_columns; counter_columns++)
            {
                //if (!isEven(counter_rows))//проверям чет
                    vectorPtr[vector_counter] = ptrarray[counter_rows][counter_columns];//если все ок то записываем четную строку
                //else {
                        //vectorPtr[vector_counter] = ptrarray[counter_rows++][counter_columns];// перескакиваем строку если нечетная
                    //counter_rows++;
                //}
                cout << vectorPtr[vector_counter] << "  "; // печать элементов одномерного массива
                vector_counter++; // инкремент индекса
            }
            cout << "\n";
        }
    }

    return 0;
}//-----------------------------------------------------------------------------------------------------------------------------------
int print2D_Array(int** ptrarray){
cout << "2D array";
    for (int i = 0; i < number_rows; i++){
        cout << endl;
        for (int j = 0; j < number_columns; j++) {
            cout  << " " << setw(8) <<  ptrarray[i][j];
        }
    }
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------



int main()              //инициализация
{

    int** ptrarray = new int* [number_rows];
    for (int count = 0; count < number_columns; count++)

        ptrarray[count] = new int [number_rows];
    for (int i = 0; i < number_rows; i++){
        //cout << endl;
        for (int j = 0; j < number_columns; j++) {
            ptrarray[i][j]=fact(i+j);

        }

    }
    print2D_Array(ptrarray);//вывод
        cout << endl;
    transformArray(ptrarray);//преобразование и вывод
    cin.get();
    return 0;
}
