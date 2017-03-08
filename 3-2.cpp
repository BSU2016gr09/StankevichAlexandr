#include <iostream> //� ������� A[N][N] ����� ������ ������, �� ���������� ������������� ���������, � �������� �� � ��������� �������. 
#include<ctime> 
using namespace std;

//void give_memory(int**&arr, int N) //������� ��������� ������ ��� ���������� �������
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

void printArray(int** arr, int N) //������� ������ ������� �� �������
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

void swapTwoRows(int**&arr,int i,int N){ //������� ������ ������� ������ ������ � ���������
	int j = 0;
		while (j != N){
			swap(arr[i][j], arr[N-1][j]);
			j++;
		}
}

void firstRowWithoutNegative(int**&arr, int N){ //������� ������ ������ ������ �� ���������� ������������� ���������
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

void initRandArray(int** arr, int N) //������� ������������� ������� ���������� �������
{
	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
			arr[i][j] = rand() % 100;
	cout << endl;
}

void initArray(int**&arr, int N) { //������� ������������� ������� � ����������
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << endl;
}

void main() //� ������� A[N][N] ����� ������ ������, �� ���������� ������������� ���������, � �������� �� � ��������� �������.
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