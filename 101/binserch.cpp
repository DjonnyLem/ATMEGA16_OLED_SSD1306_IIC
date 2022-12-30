#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int left,right;// левый и правый указатели
	int id;// под индекс массива
	int num;// искомое число
	bool flag;// флажок

	cout << " Ѕинарный поиск " << endl << endl << endl;
	int massiv[] = {0,1,7,11,22,23,27,31,45,47,55,78,95,100,151,391,409, 503};// массив отсортированный по возрастанию
	while (1)
	{
		cout << "искомое значение = ";
		cin >> num;// ввод искомого числа
		flag = false;// сброс флажка
		left = 0;// начальное значение левого указател€
		right = (sizeof(massiv) / sizeof(*massiv));// начальное значение правого указател€
		while ( left<=right && !flag) {
			id = (left + right) / 2 ;// вычисл€ем ид
			cout << "id=" << id << endl;
			if (massiv[id] == num) flag = true; //сравниваем ключ с ид-тым элементом
			else if (massiv[id] > num) right = id - 1; // двигаем правый указатель
			else left = id + 1;// двигаем левый казатель
		}
		if (flag) {
			cout << "€чейка найдена :" << id << endl;
		}	else {
			cout << "не найдено !!!! " << endl;
		}

	}

}