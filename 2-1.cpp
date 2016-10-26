#include<iostream> //Массив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N. "Перевернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й поменяется с предпоследним и т.д.) Проверить случай нечетного N.
#include<clocale>
#include<time.h>
using std::cout; using std::cin; using std::swap;
void printarray(int a[], int N) { //вывод массива размером N символов
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void rollarray(int a[], int N) { //"переворачиваем" массив.
	int i = 0;
	while (i < N / 2) { //для N нечетных просто изменяется условие такое-же:)
		swap(a[i], a[N - 1 - i]);
		i++;
	}
}
void fillarray(int N, int a[]) { //заполнение массива случайными числами из промежутка (1,N)
	int i = 0;
	while (i<N) {
		a[i] = rand() % (N + 1);
		i++;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 9;
	int a[N];
	fillarray(N, a);
	cout << "Массив: ";
	printarray(a, N);
	rollarray(a, N);
	cout << "Перевернутый массив: ";
	printarray(a, N);
	system("pause");
}