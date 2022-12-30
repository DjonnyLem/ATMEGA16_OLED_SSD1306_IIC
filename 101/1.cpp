
#include <iostream>
#include <cstdlib>
#include <ctime>

#define AMT 1000

using namespace std;

int massiv[AMT]={};


int main()
{
	setlocale(LC_ALL,"ru");
	int size = sizeof(massiv) / sizeof(massiv[0]);
	cout << size << endl;
	srand(time(0)); // рандомизация генератора случайных чисел
	int s =rand()% 5;
	cout <<"s = " << s << endl;
	cout <<"MASSIV = " << &massiv[0] <<  "|" << massiv[0] << endl;
	cout <<"MASSIV = " << &massiv[1] << "|" << massiv[1] << endl;
    cout << "RAND_MAX = " << RAND_MAX << endl; // константа, хранящая максимальный предел из интервала случайных чисел
    cout << "random number 1 = " << rand() << endl; // запуск генератора случайных чисел
	cout << "random number 2 = " << rand() << endl; // запуск генератора случайных чисел
	cout << "random number 3 = " << rand() << endl; // запуск генератора случайных чисел
	for (int i = 0; i < AMT; i++){
		int d = rand()% 1000+1;
		massiv[i] = d;
		//cout << "massiv "<< i << massiv[i] << endl;
	}
 	for ( int i; i < size; i++){
		//cout << "massiv["<< i << "] "<< massiv[i] << endl;
		if (i == size-1){
			cout << massiv[i] << endl;
		}
		else {
			cout << massiv[i]<<",";
		}
	}


	
    srand(time(0)); // рандомизация генератора случайных чисел
	
    cout << "1-random number = " <<  rand() % 100 << endl; // первый запуск генератора случайных чисел
    cout << "2-random number = " << 1 + rand() % 10 << endl; // второй запуск генератора случайных чисел
	cout << "time = " << time (0) << endl;
	cout << "stand = " <<  endl;


    system("pause");
	return 0;
}







