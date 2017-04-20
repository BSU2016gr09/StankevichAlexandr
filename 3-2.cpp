#include <iostream> //В массиве A[N][N] найти первую строку, не содержащую отрицательных элементов, и поменять ее с последней строкой. 
#include <ctime> 
#include <fstream>
using namespace std;

void give_memory(int**&arr, int N) //функция выделения памяти для двумерного массива
{
	try{
		arr = new int*[N];
		for (int i = 0; i != N; i++)
			arr[i] = new int[N];
	}
	catch (...){
		cout << "Not enough memory!!!";
	}
}

ofstream fout("result.txt");
//ifstream fin(in.txt);

//int** giveMemory(int N){
//	try{
//		int** arr = new int*[N];
//		for (int i = 0; i != N; i++)
//			arr[i] = new int[N];
//	}
//	catch (...){
//		cout << "Not enough memory!!";
//	}
//	return arr;
//}

void printArray(int** arr, int N) //функция вывода массива на консоль
{
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			fout.width(3);
			fout << arr[i][j];
		}
		fout << endl;
	}
	fout << endl;
}

void swapTwoRows(int** arr, int i, int N){ //функция замены местами данной строки и последней
	swap(arr[i], arr[N - 1]);
}

void firstRowWithoutNegative(int** arr, int N){ //функция поиска первой строки не содержащей отрицательных элементов
	int i = 0, j = 0;
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			if (arr[i][j] < 0) break;
			else if (j == N - 1) { swapTwoRows(arr, i, N); return; }
		}

	}
}

void initRandArray(int** arr, int N) //функция инициализации массива случайными числами
{
	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
			arr[i][j] = rand() % (13) - 2;
	fout << endl;
}

void initArray(int** arr, int N) { //функция инициализации массива с клавиатуры
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			cin >> arr[i][j];
		}
	}
	fout << endl;
}

void deleteMem(int**&arr, int N){
	for (int i = 0; i != N; i++){
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
}

void main() //В массиве A[N][N] найти первую строку, не содержащую отрицательных элементов, и поменять ее с последней строкой.
{
	int N;
	int **Array;
	cin >> N;
	srand(time(0));
	give_memory(Array, N);
	initRandArray(Array, N);
	printArray(Array, N);
	firstRowWithoutNegative(Array, N);
	printArray(Array, N);
	deleteMem(Array, N);
	system("pause");
	fout.close();
}