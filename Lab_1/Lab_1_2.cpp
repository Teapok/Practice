// Lab_1_1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool isEven(int i){      //�������� �� ���
    return (i % 2 == 0);
}
//-----------------------------------------------------------------------------------------------------------------------------------
int number_rows=5,      // ������
number_columns=5;       // �������
int transformArray(int**),
print2D_Array(int**);
//-----------------------------------------------------------------------------------------------------------------------------------
long int fact(int N)    //���������
{
    if(N < 0) // ���� ������������� �����
        return 0; // ���������� ����
    if (N == 0) // ���� ����,
        return 1; // ���������� ��������� �� ���� - ��� 1 =)
    else // �� ���� ��������� �������
        return N * fact(N - 1); // ������ ��������.
}
//-----------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------------------
int transformArray(int** ptrarray){
    cout << endl << "2D to 1D array" << endl << endl;
    int *vectorPtr = new int [number_rows * number_columns]; // �������� ����������� ������������� �������
    int vector_counter = 0; // ����������-������ ��� ����������� �������

    for (int counter_rows = 0; counter_rows < number_rows; counter_rows++)
    {
        if(!isEven(counter_rows)){

        }else
        {
            for (int counter_columns = 0; counter_columns < number_columns; counter_columns++)
            {
                //if (!isEven(counter_rows))//�������� ���
                    vectorPtr[vector_counter] = ptrarray[counter_rows][counter_columns];//���� ��� �� �� ���������� ������ ������
                //else {
                        //vectorPtr[vector_counter] = ptrarray[counter_rows++][counter_columns];// ������������� ������ ���� ��������
                    //counter_rows++;
                //}
                cout << vectorPtr[vector_counter] << "  "; // ������ ��������� ����������� �������
                vector_counter++; // ��������� �������
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



int main()              //�������������
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
    print2D_Array(ptrarray);//�����
        cout << endl;
    transformArray(ptrarray);//�������������� � �����
    cin.get();
    return 0;
}
