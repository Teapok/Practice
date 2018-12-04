#include <stdio.h> 
#include <cstring> 


char* Mystrrchr(char* s, int c){ 
char *p; 

if ( !s || !*s || !c ) 
return nullptr; 

for ( p = s; *p; p++ ) 
; 
for ( p -= 1; p >= s; pЧ ) 
if ( *p == (unsigned char)c ) 
return (char*)p; 
return nullptr; 
} 

int main(void){ 
char buf[BUFSIZ], *p; 
int c; 

//while ( 1 ){ 
printf("String: "); 
if ( !fgets(buf, BUFSIZ, stdin) ) 
return 1; 
if ( *buf == '\n' ) 
//break; 
if ( (p = Mystrrchr(buf, '\n')) ) 
*p = '\0'; 
printf("Char: "); 
c = getchar(); 
getchar(); 
if ( (p = Mystrrchr(buf, c)) ) 
printf("My function: %s\n", p); 
else 
printf("Can't find %c in string %s\n", (unsigned char)c, buf); 
// } 
//char str[] = "my text"; 
char* pch = strrchr(buf,*p); 
printf("Standart Func: %s\n", pch); 

return 0; 
}
 
#include <iostream> 
#include <iomanip> 

using namespace std; 

bool check(int i){ //проверка на чет 
if (i % 2 != 0) 
return true; 
} 
//---------------------------------------------------------------------------------------------------------------------------------Ч 
int number_rows=5, // строки 
number_columns=5; // столбцы 
int transformArray(int**), 
print2D_Array(int**); 
//---------------------------------------------------------------------------------------------------------------------------------Ч 
long int fact(int N) //факториал 
{ 
if(N < 0) // если пользователь ввел отрицательное число 
return 0; // возвращаем ноль 
if (N == 0) // если пользователь ввел ноль, 
return 1; // возвращаем факториал от нул€ - это 1 =) 
else // ¬о всех остальных случа€х 
return N * fact(N - 1); // делаем рекурсию. 
} 
//---------------------------------------------------------------------------------------------------------------------------------Ч 
int main() //инициализаци€ 
{ 

int** ptrarray = new int* [number_rows]; 
for (int count = 0; count < number_columns; count++) 

ptrarray[count] = new int [number_rows]; 
for (int i = 0; i < number_rows; i++){ 
//cout Ђ endl; 
for (int j = 0; j < number_columns; j++) { 
ptrarray[i][j]=fact(i+j); 

} 

} 
print2D_Array(ptrarray);//вывод 
cout Ђ endl; 
transformArray(ptrarray);//преобразование и вывод 
cin.get(); 
return 0; 
} 
//---------------------------------------------------------------------------------------------------------------------------------Ч 
int transformArray(int** ptrarray){ 
cout Ђ endl Ђ "2D to 1D array" Ђ endl Ђ endl; 
int *vectorPtr = new int [number_rows * number_columns]; // создание одномерного динамического массива 
int vector_counter = 0; // переменна€-индекс дл€ одномерного массива 

for (int counter_rows = 0; counter_rows < number_rows; counter_rows++) 
{ 
for (int counter_columns = 0; counter_columns < number_columns; counter_columns++) 
{ 
if (check(counter_rows) == !true)//провер€м чет 
vectorPtr[vector_counter] = ptrarray[counter_rows][counter_columns];//если все ок то записываем четную строку 
else vectorPtr[vector_counter] = ptrarray[++counter_rows][counter_columns];// перескакиваем строку если нечетна€ 
cout Ђ vectorPtr[vector_counter] Ђ " "; // печать элементов одномерного массива 
vector_counter++; // инкремент индекса 
} 
} 
return 0; 
}//---------------------------------------------------------------------------------------------------------------------------------Ч 
int print2D_Array(int** ptrarray){ 
cout Ђ "2D array"; 
for (int i = 0; i < number_rows; i++){ 
cout Ђ endl; 
for (int j = 0; j < number_columns; j++) { 
cout Ђ " " Ђ setw(8) Ђ ptrarray[i][j]; 
} 
} 
return 0; 
} 
//-----------------------------------------------------------------------------------------------------------------------------------