#include <stdio.h> 
#include <cstring> 


char* Mystrrchr(char* s, int c){ 
char *p; 

if ( !s || !*s || !c ) 
return nullptr; 

for ( p = s; *p; p++ ) 
; 
for ( p -= 1; p >= s; p� ) 
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

bool check(int i){ //�������� �� ��� 
if (i % 2 != 0) 
return true; 
} 
//---------------------------------------------------------------------------------------------------------------------------------� 
int number_rows=5, // ������ 
number_columns=5; // ������� 
int transformArray(int**), 
print2D_Array(int**); 
//---------------------------------------------------------------------------------------------------------------------------------� 
long int fact(int N) //��������� 
{ 
if(N < 0) // ���� ������������ ���� ������������� ����� 
return 0; // ���������� ���� 
if (N == 0) // ���� ������������ ���� ����, 
return 1; // ���������� ��������� �� ���� - ��� 1 =) 
else // �� ���� ��������� ������� 
return N * fact(N - 1); // ������ ��������. 
} 
//---------------------------------------------------------------------------------------------------------------------------------� 
int main() //������������� 
{ 

int** ptrarray = new int* [number_rows]; 
for (int count = 0; count < number_columns; count++) 

ptrarray[count] = new int [number_rows]; 
for (int i = 0; i < number_rows; i++){ 
//cout � endl; 
for (int j = 0; j < number_columns; j++) { 
ptrarray[i][j]=fact(i+j); 

} 

} 
print2D_Array(ptrarray);//����� 
cout � endl; 
transformArray(ptrarray);//�������������� � ����� 
cin.get(); 
return 0; 
} 
//---------------------------------------------------------------------------------------------------------------------------------� 
int transformArray(int** ptrarray){ 
cout � endl � "2D to 1D array" � endl � endl; 
int *vectorPtr = new int [number_rows * number_columns]; // �������� ����������� ������������� ������� 
int vector_counter = 0; // ����������-������ ��� ����������� ������� 

for (int counter_rows = 0; counter_rows < number_rows; counter_rows++) 
{ 
for (int counter_columns = 0; counter_columns < number_columns; counter_columns++) 
{ 
if (check(counter_rows) == !true)//�������� ��� 
vectorPtr[vector_counter] = ptrarray[counter_rows][counter_columns];//���� ��� �� �� ���������� ������ ������ 
else vectorPtr[vector_counter] = ptrarray[++counter_rows][counter_columns];// ������������� ������ ���� �������� 
cout � vectorPtr[vector_counter] � " "; // ������ ��������� ����������� ������� 
vector_counter++; // ��������� ������� 
} 
} 
return 0; 
}//---------------------------------------------------------------------------------------------------------------------------------� 
int print2D_Array(int** ptrarray){ 
cout � "2D array"; 
for (int i = 0; i < number_rows; i++){ 
cout � endl; 
for (int j = 0; j < number_columns; j++) { 
cout � " " � setw(8) � ptrarray[i][j]; 
} 
} 
return 0; 
} 
//-----------------------------------------------------------------------------------------------------------------------------------