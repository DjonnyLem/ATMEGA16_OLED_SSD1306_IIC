#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//сортировка выбором (перестановкой)SelectionSort
void sort1(int massiv[], int size) {
	int min;
	int dump;

	for (int i = 0; i < size; i++) {
		min = i;// предполагаем что выбранный элемнт минимальный

		for (int n = i + 1; n < size; n++) {
			if (massiv[n] < massiv[min]) min = n;// находим минимальный в оставшейся части массива
		}
		dump = massiv[min];// пишем в дамп минимальное значение
		massiv[min] = massiv[i];// пишем выбранное значение на место минимального
		massiv[i] = dump;// пишем в выбранный элемент минимальное значение
	}
	// вывод сортированного массива
	for (int n = 0; n < size; n++) {
		//cout << massiv[n] << ",";
		printf("%d ", massiv[n]);
	
	}
}

void main(){
	int massiv[] = {524,3,8,1,0};
	int size = sizeof(massiv) / sizeof(massiv[0]);
	printf ("sizeof(massiv) = %lu\n", sizeof(massiv));
	printf ("sizeof(massiv[0] = %lu\n", sizeof(massiv[0]));
	printf ("size = %d\n", size);
	printf ("1 = %d\n", massiv[0]);
	sort1 (massiv, size);


	
}




