#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int left,right;// ����� � ������ ���������
	int id;// ��� ������ �������
	int num;// ������� �����
	bool flag;// ������

	cout << " �������� ����� " << endl << endl << endl;
	int massiv[] = {0,1,7,11,22,23,27,31,45,47,55,78,95,100,151,391,409, 503};// ������ ��������������� �� �����������
	while (1)
	{
		cout << "������� �������� = ";
		cin >> num;// ���� �������� �����
		flag = false;// ����� ������
		left = 0;// ��������� �������� ������ ���������
		right = (sizeof(massiv) / sizeof(*massiv));// ��������� �������� ������� ���������
		while ( left<=right && !flag) {
			id = (left + right) / 2 ;// ��������� ��
			cout << "id=" << id << endl;
			if (massiv[id] == num) flag = true; //���������� ���� � ��-��� ���������
			else if (massiv[id] > num) right = id - 1; // ������� ������ ���������
			else left = id + 1;// ������� ����� ��������
		}
		if (flag) {
			cout << "������ ������� :" << id << endl;
		}	else {
			cout << "�� ������� !!!! " << endl;
		}

	}

}