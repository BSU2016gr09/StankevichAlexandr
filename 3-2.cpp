#include <iostream> //В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.
#include <time.h>
using std::cin; using std::cout; using std::swap;
void sortarray(float a[], int N) { //сортировка массива для последующей проверки его членов
	int i = 0, j = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (a[i] > a[j]) swap(a[i], a[j]);
			j++;
		}
		i++;
	}
}
void printarray(float a[], int N) { //вывод массива размером N символов
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void fillarray(int N, float a[]) { //заполнение массива случайными числами из промежутка (0,10)
	int i = 0;
	float q, q1;
	while (i<N) {
		q = (rand() % 11);
		q1 = (rand() % 11);
		if (q1 != 0) a[i] = 1 + (q / q1); else a[i] = 1 + (q1 / q);
		//a[i] = rand() % 11;
		i++;
	}
}
int valueofsame(float a[], int N) { //нахождение количества элементов повторяющихся более одного раза
	int i = 0,k, value, sumofvalue = 0;
	while (i < N) {
		value = 0; k = i;
		while (a[i] == a[i + 1]) {
			value++; i++;
		}
		i = k;
		if (value > 0) sumofvalue++;
		i++;
	}
	return sumofvalue;
}
int main() { //В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.
	setlocale(LC_ALL, "russian");
	srand(time(0));
	const int N = 10;
	float a[N];
	fillarray(N, a);
    cout << "Массив:\n";
	printarray(a, N);
	sortarray(a, N);
	valueofsame(a, N);
	cout << "Различных элементов, которые встречаются в данном массиве более одного раза: " << valueofsame(a,N) << "\n";
	system("pause");
}