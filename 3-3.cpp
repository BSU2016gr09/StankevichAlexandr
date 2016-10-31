#include <iostream> //В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.
#include <time.h>
using std::cin; using std::cout; using std::swap;
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
		a[i] = rand() % 11;
		i++;
	}
}
int valueofsame(float a[], int N) { //нахождение последовательности одинаковых элементов
	int i = 0, k, value, sumofvalue = 0;
	while (i < N) {
		value = 1; k = i;
		while (a[i] == a[i + 1]) {
			value++; i++;
		}
		i = k;
		if (value > sumofvalue) sumofvalue=value;
		i++;
	}
	return sumofvalue;
}
int main() { //В массиве размера N, заполненного случ.числами от 0 до 10, определить максимальную длину последовательности равных элементов.
	setlocale(LC_ALL, "russian");
	srand(time(0));
	const int N = 10;
	float a[N];
	fillarray(N, a);
	cout << "Массив:\n";
	printarray(a, N);
	valueofsame(a, N);
	cout << "Максимальная длина последовательности повторяющихся элементов = " << valueofsame(a, N) << "\n";
	system("pause");
}