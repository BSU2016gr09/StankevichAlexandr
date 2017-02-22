#include<iostream> //Даны точки плоскости своими координатами в виде двух одномерных массивов. Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include<ctime>
#include<clocale>
using namespace std;
void initArray(int* arr, int N){ //функция инициализации массива случайными числами
	int j = 0;
	while (j < N){
		arr[j++] = rand() % N;
	}
}

float getDistance(int oX, int oY, int a, int b, int c){ //функция вычисления растояния от точек до прямой 
	return abs(a*oX + b*oY + c) / sqrt(a*a + b*b);
}

void printPoints(int* oX, int*oY, int N){ //функция вывода точек
	int i = 0;
	while (i < N){
		cout << "(" << oX[i] << " , " << oY[i] << ")  " ;
		i++;
	}
	cout << "\n";
}

void initGetDistances(int* distances, int* oX, int* oY, int N,int a,int b,int c){ //функция инициализации массива distances
	int i = 0;
	while (i < N){
		distances[i] = getDistance(oX[i], oY[i], a, b, c);
		i++;
	}
}

void sortPoints(int* distances, int* oX, int* oY,int N){ //функция сортировки точек по условию
		int i=0;
		while (i < N - 1){
			int j = i+1;
			while (j < N - 1){
				if (distances[j] > distances[j + 1]) { 
					swap(distances[j], distances[j + 1]);
					swap(oX[j], oX[j + 1]);
					swap(oY[j], oY[j + 1]);
				}
				j++;
			}
			i++;
		}
}

int main(){ //Даны точки плоскости своими координатами в виде двух одномерных массивов. Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int a, b, c, N;
	cout << "Количество точек:";
	cin >> N;
	cout << "\n";
	int* oX = new int[N];
	int* oY = new int[N];
	int* distances = new int[N];
	cout << "Введите коэффиценты прямой:";
	cin >> a >> b >> c;
	initArray(oX, N);
	initArray(oY, N);
	printPoints(oX, oY, N);
	initGetDistances(distances, oX, oY,N, a, b, c);
	sortPoints(distances, oX, oY, N);
	printPoints(oX, oY, N);
	delete[] distances;
	delete[] oX;
	delete[] oY;
	system("pause");
}