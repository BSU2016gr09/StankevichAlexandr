#include <iostream> //В массиве A[N][N] найти первую строку, не содержащую отрицательных элементов, и поменять ее с последней строкой. 
#include<ctime> 
using namespace std;

//void give_memory(int**&arr, int N) //функция выделения памяти для двумерного массива
//{
//	arr = new int*[N];
//	for (int i = 0; i != N; i++)
//		arr[i] = new int[N];
//}

int** giveMemory(int N){
	int** arr = new int*[N];
	for (int i = 0; i != N; i++)
		arr[i] = new int[N];
	return arr;
}

void printArray(int** arr, int N) //функция вывода массива на консоль
{
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			cout.width(3);
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void swapTwoRows(int**&arr,int i,int N){ //функция замены местами данной строки и последней
	int j = 0;
		while (j != N){
			swap(arr[i][j], arr[N-1][j]);
			j++;
		}
}

void firstRowWithoutNegative(int**&arr, int N){ //функция поиска первой строки не содержащей отрицательных элементов
	int c = 0, i = 0, j = 0;
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			if (arr[i][j] < 0) c++;
		}
		if (c == 0) {
			swapTwoRows(arr, i,N);
			break;
		}
		c = 0;
	}
}

void initRandArray(int** arr, int N) //функция инициализации массива случайными числами
{
	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
			arr[i][j] = rand() % 100;
	cout << endl;
}

void initArray(int**&arr, int N) { //функция инициализации массива с клавиатуры
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << endl;
}

void main() //В массиве A[N][N] найти первую строку, не содержащую отрицательных элементов, и поменять ее с последней строкой.
{
	int N;
	
	cin >> N;
	int **Array = giveMemory(N);
	initRandArray(Array, N);
	printArray(Array, N);
	firstRowWithoutNegative(Array, N);
	printArray(Array, N);
	delete[] Array;
	srand(time(0));
	system("pause");
}