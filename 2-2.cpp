﻿#include<iostream> //Массив целых чисел размера N проинициализировать случайными числами из промежутка от -N до N. Циклически сдвинуть элементы массива вправо на 1 элемент (последний элемент станет первым, 1-й станет 2-м, 2-й станет 3-м и т.д.) потом циклически сдвинуть элементы массива влево на 1 элемент (первый элемент станет последним, 2-й станет 1-м и т.д)
#include<clocale>
#include<time.h>
using std::cout; using std::cin; using std::swap;
void printarray(int a[], int N) { //вывод массива размером n символом
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void fillarray(int a[], int N) { //заполнение массива числами из промежутка (-N,N)
	int i = 0;
	int min = -N, max = N;
	while (i<N) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void shiftarrayright(int a[], int N) { //сдвиг массива вправо на один элемент
	int k, i = 1;
	k = a[N - 1];
	i = N - 1;
	while (i >0) {
		a[i] = a[i - 1];
		i--;
	}
	a[0] = k;
}
void shiftarrayleft(int a[], int N) { //сдвиг массива влево на один элемент
	int k, i = 1;
	k = a[0];
	while (i <N - 1) {
		a[i] = a[i + 1];
		i++;
	}
	a[N - 1] = k;
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 10;
	int a[N];
	fillarray(a, N);
	cout << "Исходный массив: ";
	printarray(a, N);
	shiftarrayright(a, N);
	cout << "Сдвинутый вправо на один элемент массив: ";
	printarray(a, N);
	shiftarrayleft(a, N);
	cout << "Сдвинутый влево на один элемент массив: ";
	printarray(a, N);
	system("pause");
}