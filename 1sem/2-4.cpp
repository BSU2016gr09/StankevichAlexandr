#include<iostream> //Массив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N. "Перетусовать" элементы массива двумя способами, предложенными на паре: с использованием доп.массива и просто меняя местами случайные элементы.
#include<time.h>
#include<clocale>
using std::cout; using std::cin; using std::swap;
void shuffleelem(int a[], int b[], int N) {
	int k, i = 0;
	while (i < N) {
		k = rand() % (N - 1);
		b[i] = a[k];
		k = 0;
		i++;
	}
}
void shuffleelements(int a[], int N) { //перетусовка элементов массива меняя местами случайные элементы
	int i = 0, b, c;
	while (i < N*N) {
		b = rand() % (N - 1);
		c = rand() % (N - 1);
		swap(a[c], a[b]);
		i++;
	}
}
void fillarray(int a[], int N) { //заполнение массива последовательными числами из промежутка (1,N);
	int i = 0;
	a[0] = 1;
	while (i<N) {
		a[i + 1] = a[i] + 1;
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
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 10;
	int a[N], b[N];
	fillarray(a, N);
	cout << "Исходный массив: ";
	printarray(a, N);
	shuffleelements(a, N);
	cout << "Массив, перетусованный меняя местами случайные элементы ";
	printarray(a, N);
	shuffleelem(a, b, N);
	cout << "Массивб перетусованный с помощью вспомогательного массива: ";
	printarray(b, N);
	system("pause");
}
