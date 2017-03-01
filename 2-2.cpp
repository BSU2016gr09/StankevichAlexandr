#include<iostream>
#include<ctime>
using namespace std; //Реализуйте алгоритм XORShift нахождения псевдослучайных чисел в качестве отдельной функции, чтобы потом выполнять задания на массивы(там где надо случайными числами заполнить массив)!
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

void xorSHIFT(int* arr, int k){
	int i = 1, tmp;
	arr[0] = k;
	while (arr[i]){
		tmp ^= arr[i - 1] << 13;
		tmp ^= tmp >> 15;
		arr[i] ^= tmp << 5;
		i++;
	}


}

int main(){ //Реализуйте алгоритм XORShift нахождения псевдослучайных чисел в качестве отдельной функции, чтобы потом выполнять задания на массивы (там где надо случайными числами заполнить массив)!
	int N, k;
	cin >> N >> k;
	int* Array;
	giveMemory(Array, N);
	xorSHIFT(Array, k);
	printArray(Array, N);
	delete[] Array;
	system("pause");
}