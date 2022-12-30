#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int left,right;// левый и правый указатели
	int id;// под индекс массива
	int num;// искомое число
	bool flag;// флажок

	cout << " Бинарный поиск " << endl << endl << endl;
	int massiv[] = {0,1,7,11,22,23,27,31,45,47,55,78,95,100,151,391,409, 503};// массив отсортированный по возрастанию
	while (1)
	{
		cout << "искомое значение = ";
		cin >> num;// ввод искомого числа
		flag = false;// сброс флажка
		left = 0;// начальное значение левого указателя
		right = (sizeof(massiv) / sizeof(*massiv));// начальное значение правого указателя
		while ( left<=right && !flag) {
			id = (left + right) / 2 ;// вычисляем ид
			cout << "id=" << id << endl;
			if (massiv[id] == num) flag = true; //сравниваем ключ с ид-тым элементом
			else if (massiv[id] > num) right = id - 1; // двигаем правый указатель
			else left = id + 1;// двигаем левый казатель
		}
		if (flag) {
			cout << "їїїїїї їїїїїїї:" << id << endl;
		}	else {
			cout << "її їїїїїїї !!!! " << endl;
		}

	}

}
