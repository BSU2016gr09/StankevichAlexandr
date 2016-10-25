#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
void IsPositiveOrNegative(int a[], int b[], int c[], int n, int&j, int&l) { //сортировка в два массива: с положительными числами и с отрицательными
	int i = 0;
	while (i < n) {
		if (a[i] > 0) {
			b[j] = a[i]; j++;
		}
		else if (a[i] < 0) {
			c[l] = a[i]; l++;
		}
		i++;
	}
}
void PrintArray(int a[], int n) { //вывод массива размером n символом
	int i = 0;
	while (i < n) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void FillArray(int n, int a[], int min, int max) { //заполнение массива числами из промежутка (min,max)
	int i = 0;
	while (i<n) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}

}
int main()//Объявить массив А вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Разделить массив А на два массива: положительные записать в массив В, отрицательные - в С.
{
	srand(time(0));
	setlocale(0, "");
	cout << "Объявить массив А вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Разделить массив А на два массива: положительные записать в массив В, отрицательные - в С.\n";
	const int n = 100;
	int a[n], b[n], c[n], j = 0, l = 0;
	FillArray(n, a, -50, 50);
	IsPositiveOrNegative(a, b, c, n, j, l);
	cout << "Положительные элементы массива: ";
	PrintArray(b, j);
	cout << "\n" << "Отрицательные элементы массива: ";
	PrintArray(c, l);
	system("pause");
}
