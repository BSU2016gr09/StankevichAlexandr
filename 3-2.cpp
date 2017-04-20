#include <iostream> //� ������� A[N][N] ����� ������ ������, �� ���������� ������������� ���������, � �������� �� � ��������� �������. 
#include <ctime> 
#include <fstream>
using namespace std;

void give_memory(int**&arr, int N) //������� ��������� ������ ��� ���������� �������
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

void printArray(int** arr, int N) //������� ������ ������� �� �������
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

void swapTwoRows(int**&arr, int i, int N){ //������� ������ ������� ������ ������ � ���������
		swap(arr[i], arr[N - 1]);
}

void firstRowWithoutNegative(int**&arr, int N){ //������� ������ ������ ������ �� ���������� ������������� ���������
	int c = 0, i = 0, j = 0;
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			if (arr[i][j] < 0) c++;
		}
		if (c == 0) {
			swapTwoRows(arr, i, N);
			break;
		}
		c = 0;
	}
}

void initRandArray(int** arr, int N) //������� ������������� ������� ���������� �������
{
	for (int i = 0; i != N; i++)
		for (int j = 0; j != N; j++)
			arr[i][j] = rand() %(13)-2;
	fout << endl;
}

void initArray(int**&arr, int N) { //������� ������������� ������� � ����������
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			cin >> arr[i][j];
		}
	}
	fout << endl;
}

void main() //� ������� A[N][N] ����� ������ ������, �� ���������� ������������� ���������, � �������� �� � ��������� �������.
{
	int N;
	int **Array;
	cin >> N;
	srand(time(0));
	give_memory(Array,N);
	initRandArray(Array, N);
	printArray(Array, N);
	firstRowWithoutNegative(Array, N);
	printArray(Array, N);
	delete[] Array;
	system("pause");
	fout.close();
}