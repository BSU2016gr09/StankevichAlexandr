#include<clocale> //Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include<iostream>
#include<ctime>
using namespace std;

void initArray(float* arr, int N){ //функция инициализации массива случайными числами
	int j = 0;
	while (j < N){
		arr[j++] = rand() % N;
	}
}

void positiveSort(float* a, int N){ //положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
	int i = N - 1,j;
	while(i >= 0){
		if (*(a + i) > 0){
			j = i;
			while(j < N - 1){
				swap(*(a + j), *(a + j + 1));
				j++;
			}
			N--;
		}
		i--;
	}
}

void printArray(float* arr, int N){ //функция вывода массива на консоль
	int j = 0;
	while (j < N){
		cout << arr[j++] << " ";
	}
	cout << "\n";
}

void inputArray(float* arr, int N){ //функция инициализации массива с клавиатуры
	int j = 0;
	while (j < N){
		cin >> arr[j++];
	}
}


void sortNegatives(float*arr, int N){ //сортировка отрицательных элементов массива "пузырьком"
	int i = 0;
	while (i < N - 1){
		int j = 0;
		while (j < N - 1){
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
			j++;
		}
		i++;
	}
}

int main(){ //Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
	srand(time(0));
	int N;
	cin >> N;
	float*Array = new float[N];
	inputArray(Array, N);
	printArray(Array, N);
	positiveSort(Array, N);
	printArray(Array, N);
	sortNegatives(Array, N);
	system("pause");
}