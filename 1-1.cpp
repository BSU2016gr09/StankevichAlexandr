#include<iostream>
#include<ctime>
using namespace std; //Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.

void initArray(int* arr, int N){ //функция инициализации массива случайными числами
	int j = 0;
	while (j < N){
		arr[j++] = rand() % N;
	}
}

void inputArray(int* arr, int N){ //функция инициализации массива с клавиатуры
	int j = 0;
	while (j < N){
		cin >> arr[j++];
	}
}

void printArray(int* arr, int N){ //функция вывода массива на консоль
	int j = 0;
	while (j < N){
		cout << arr[j++] << " ";
	}
}

void sortArray(int*arr, int N, int k){ //сортировка массива "пузырьком" начиная с k-го элемента
	int i = k - 1;
	while (i < N - 1){
		int j = k - 1;
		while (j < N - 1){
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
			j++;
		}
		i++;
	}
}

void giveMemory(int* &arr, int N){
	try{
		arr = new int[N];
	}
	catch(...){
		cout << "Not enough memory";
	}
}

int main(){ //Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
	srand(time(0));
	int N, k;
	cin >> N;
	int* Array;
	giveMemory(Array, N);
	initArray(Array, N);
	printArray(Array, N);
	cout << "\n\n\n";
	cin >> k;
	sortArray(Array, N, k);
	printArray(Array, N);
	delete[] Array;
	cout << "\n\n\n";
	system("pause");
}