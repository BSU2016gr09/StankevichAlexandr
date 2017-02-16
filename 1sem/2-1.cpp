#include<iostream> //Массив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N. "Перевернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й поменяется с предпоследним и т.д.) Проверить случай нечетного N.
#include<clocale>
#include<time.h>
using std::cout; using std::cin; using std::swap;
void printarray(float a[], int N) { //вывод массива размером N символов
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void rollarray(float a[], int N) { //"переворачиваем" массив.
	int i = 0;
	while (i < N / 2) { //для N нечетных условие такое-же:)
		swap(a[i], a[N - 1 - i]);
		i++;
	}
}
void fillarray(int N, float a[]) { //заполнение массива случайными числами из промежутка (1,N)
	int i = 0;
	float q, q1;
	while (i<N) {
		q = (rand() % N + 1);
		q1 = (rand() % N);
		if (q1 != 0) a[i] = 1 + (q / q1); else a[i] = 1+(q1 / q);
		i++;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 9;
	float a[N];
	fillarray(N, a);
	cout << "Массив: ";
	printarray(a, N);
	rollarray(a, N);
	cout << "Перевернутый массив: ";
	printarray(a, N);
	system("pause");
}
