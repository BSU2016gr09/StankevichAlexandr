#include<iostream> //Массив А целых чисел размера N проинициализировать случайными числами из промежутка от -N до N. Не используя функции из задачи 2-2 Написать функции циклического сдвинга элементы массива вправо на k элементов (1-й станет 1+k -ым, 2-й станет 2+k -ым и т.д.) и влево на k элементов. В main написать вызов этих функций для числа k, которое вводит пользователь.
#include<clocale>
#include<time.h>
using std::cout; using std::cin;
void fillarray(int a[], int N) { //заполнение массива числами из промежутка (-N,N)
	int i = 0;
	int min = -N, max = N;
	while (i<N) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void printarray(int a[], int N) { //вывод массива размером N символов
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void shiftarrayleft(int a[], int N, int k) { //сдвигаем массив на k элементов влево
	int i = 1, c = 0, j;
	for (c = 0; c < k; c++) {
		j = a[0];
		for (i = 1; i<N; i++)
		{
			a[i - 1] = a[i];
		}
		a[N - 1] = j;
	}
}
void shiftarrayright(int a[], int N, int k) { //сдвигаем массив на k элементов вправо
	int j, i, c;
	for (c = 0; c < k; c++) {
		j = a[N - 1];
		for (i = N - 1; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = j;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 10;
	int a[N], newarray[N], k;
	cout << "Введите на сколько сдвинуть массив вправо\n";
	cin >> k;
	fillarray(a, N);
	cout << "Исходный массив: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayleft(a, N, k);
	cout << "Массив сдвинутый влево на " << k << " позиций: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayright(a, N, k);
	cout << "Массив сдвинутый вправо на " << k << " позиций: ";
	printarray(a, N);
	cout << "\n\n";
	system("pause");
}