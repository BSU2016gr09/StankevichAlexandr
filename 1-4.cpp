#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
void FillArray(int n, int a[], int min, int max) { //заполнение массива числами из промежутка (min,max)
	int i = 0;
	while (i<n) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void PrintElementsWithOddNumbers(int&n, int a[]) { //ввывод элементов массива с нечетными номерами
	cout << "Числа с нечетными номерами:";
	while (n < 99) {
		cout << a[n] << " ";
		n += 2;
	}
}
void PrintElementsWithEvenNumbers(int&n, int a[]) { //ввывод элементов массива с четными номерами
	cout << "Числа с четными номерами:";
	while (n < 99) {
		cout << a[n] << " ";
		n += 2;
	}
}
int main()//Объявить массив вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Вывести значения сначала элементов с нечетными коэффициентами (1-й, 3-й, 5-й,...) а затем - с четными.
{
	int n;
	srand(time(0));
	setlocale(0, "");
	cout << "Объявить массив вещественных чисел размера N (число N объявить как константу). Проинициализировать значения элементов массива случайными числами из промежутка от -50 до 50. Вывести значения сначала элементов с нечетными коэффициентами (1-й, 3-й, 5-й,...) а затем - с четными.\n";
	const int k = 100;
	int a[k];
	FillArray(k, a, -50, 50);
	n = 1;
	PrintElementsWithOddNumbers(n, a);
	n = 0;
	PrintElementsWithEvenNumbers(n, a);
	system("pause");
}