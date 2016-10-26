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
void shiftarrayright(int a[],int b[], int N, int k) { //сдвигаем массив на k элементов вправо
	int i = 0;
	while (i < N) {
		if (i + k < N) b[i + k] = a[i];
		else b[i + k - N] = a[i];
		i++;
	}
}
void shiftarrayleft(int a[],int b[], int N, int k) { //сдвигаем массив на k элементов влево
	int i;
	i = 0;
	while (i <N) {
		if (i-k >= 0) b[i-k] = a[i];
		else b[i-k+N] = a[i];
		i++;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 10;
	int a[N], b[N], k;
	cout << "Введите на сколько сдвинуть массив\n";
	cin >> k;
	fillarray(a, N);
	cout << "Исходный массив: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayright(a,b, N, k);
	cout << "Массив сдвинутый вправо на " << k << " позиций: ";
	printarray(b, N);
	cout << "\n\n";
	shiftarrayleft(b,a, N, k);
	cout << "Массив сдвинутый влево на " << k << " позиций: ";
	printarray(a, N);
	cout << "\n\n";
	system("pause");
}

