

#include <iostream>
#include <cmath>

float massiv[81] ={};
int size;
int i = 0;
using namespace std;
int main(){
	for (float x= -40; x <= 40; x += 1){
		float j = x/10;		
		float c =	(5.0 * pow(j,2)) + (6.0 * j) - 3.0;
		massiv[i] = c;
		i++;

	}
	// вывод  массива
	cout << "Массив значений функции:" << endl;
	size = sizeof(massiv) / sizeof(massiv[0]);
	for (int n = 0; n < size; n++) {
		
		cout << massiv[n] << ",";
		//printf("%d ", massiv[n]);
	}
	cout << endl;
}


/*
float massiv1[] = {53,49.65,46.4,43.25,40.2,37.25,34.4,31.65,29,26.45,
			24,21.65,19.4,17.25,15.2,13.25,11.4,9.65,8,6.45,
			5,3.65,2.4,1.25,0.2,-0.75,-1.6,-2.35,-3,-3.55,
			-4,-4.35,-4.6,-4.75,-4.8,-4.75,-4.6,-4.35,-4,-3.55,
			-3,-2.35,-1.6,-0.75,0.2,1.25,2.4,3.65,5,6.45,
			8,9.65,11.4,13.25,15.2,17.25,19.4,21.65,24,26.45,
			29,31.65,34.4,37.25,40.2,43.25,46.4,49.65,53,56.45,
			60,63.65,67.4,71.25,75.2,79.25,83.4,87.65,92,96.45,101};

*/

/*
#include <iostream>

using namespace std;
int main(){
	setlocale(LC_ALL,"ru");
	int t;
	int s;
	int i = 1;
	int count = 0;
	do{
		cout << "Введите число: ";
		cin >> s;
		cout << "Вы ввели число: " << s << endl;
		if (i == 1) t = s;
		else if (s < t) t = s;		
		i++;				
	} 
	while (i<=10);
	
	cout << "Лимит ввода закончился!" << endl
		<< "Минимальное введённое число: " << t << endl;		
}

*/
/*	
#include <iostream>
using namespace std;
int main(){
	setlocale(LC_ALL,"ru");
	int S = 0;
	int i = -3;
	while (i <= 10)
	{
		if (i != 0){
			S += i * i;	
			}
		i ++;
		}

	cout << "S = " << S << endl;
}
*/
