/*
Generator Random Numbers
Генератор случайных чисел
file name: generatorRandomNambers.cpp
*/
/*
#include <iostream> // подключение функций ввода/вывода

using namespace std; // чтобы не записывать std::cin

//генерируем целый случайный массив
void int_massiv()
{
   // определяем переменные
   int a[10];
   int i;

   srand(time(0)); // инициализация генерации случайных чисел

   //генерируем целый случайный массив из 10 эелментов от 1 до 5
   for (i = 0; i < 10; i++)
     a[i] = 1 + rand() % 5;
   for (i = 0; i < 10; i++)
     cout<<a[i]<<" "; // вывод результата на экране
}

//генерируем вещественный случайный массив
void double_massiv()
{
   // определяем переменные
   double b[10];
   int i;

   srand(time(0)); // инициализация генерации случайных чисел

   //генерируем вещественный случайный массив из 10 эелментов от 1 до 5
   for (i = 0; i < 10; i++)
     b[i] = 1.0 + 4.0 * rand() / (float)RAND_MAX;
   for (i = 0; i < 10; i++)
     cout<<b[i]<<" "; // вывод результата на экране
}

int main()
{
   int_massiv();
   cout<<"\n";
   double_massiv();
   cin.get(); // ожидаем нажатия пользователем клавиши
}
///////////////////////////////////////////////////////////////////////////
*/
//#include "pch.h"
#include "iostream"
#include "cstdlib"
using namespace std;
void randommassiv(int massiv[], int size)
{
	//int massiv[1000] = {};
	int i=0;
	for (int j = 0; j < size; j++); // Задаем массив из 30 чисел
	{
	massiv[i] = 1 + rand() % 50; //Генерация случайных чисел от 1 до 50
	//cout << massiv[i] << endl;
	}
/*
	// вывод сортированного массива
	for (int n = 0; n < size; n++) {
		cout << massiv[n] << ",";
		//printf("%d ", massiv[n]);
	}
*/
}
int massiv[1000] = {};

int main()
{
	int size = sizeof(massiv) / sizeof(massiv[0]);
	cout << size;
	randommassiv(massiv, size);
	//cin.get();
}


