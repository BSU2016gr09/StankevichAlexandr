#include<iostream> //Реализовать линейный конгруэнтный генератор псевдослучайных чисел.
//(a)Используя коэффициенты из википедии, например a = 4096, c = 150889, m = 714025.
//(b)Подобрав собственные коэффициенты по правилам, не использую готовые коэффициенты из википедии.
#include<ctime>
using namespace std;

void giveMemory(int* &arr, int N){
	try{
		arr = new int[N];
	}
	catch (...){
		cout << "Not enough memory";
	}
}

void printArray(int* arr, int N){ //функция вывода массива на консоль
	int j = 0;
	while (j < N){
		cout << arr[j++] << " ";
	}
}

void generate1(int*&arr, int k){ //генерирование псевдослучайных чисел с данными в дз коэффицентами
	int i = 1;
	arr[0] = k;
	while (arr[i]){
		arr[i] = (4096 * arr[i - 1] + 150889) % 714025;
		i++;
	}
}

void generate2(int*&arr, int k){ //генерирование псевдослучайных чисел со своими коэффицентами
	int i = 1;
	arr[0] = k;
	while (arr[i]){
		arr[i] = (9238 * arr[i - 1] + 83784) % 98435;
		i++;
	}
}


int main(){ //Реализовать линейный конгруэнтный генератор псевдослучайных чисел.
	//(a)Используя коэффициенты из википедии, например a = 4096, c = 150889, m = 714025.
	//(b)Подобрав собственные коэффициенты по правилам, не использую готовые коэффициенты из википедии.
	int N, k;
	cin >> N >> k;
	int* Array;
	giveMemory(Array, N);
	generate2(Array, k);
	printArray(Array, N);
	delete[]Array;
	system("pause");
}