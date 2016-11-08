#include<iostream>
#include<clocale>
#include<time.h>
#include <conio.h>
#include <Windows.h>
using std::cin; using std::cout;
const int maxsize=5;
void initArray(int a[]){
	int i = 0;
	while (i < maxsize) {
		a[i++] = rand() % maxsize + 1;
	}
}
void initArray(int a[],int init) {
	int i = 0;
	while (i < maxsize) {
		a[i++] = init;
	}
}
void printNumber(int a[]) {
	int i = maxsize-1;
	while (i >=0) {
		if(a[i]!=0)	cout << a[i];
		i--;
	}
	cout << "\n";
}
void inputArray(int a[]) {
	int i = maxsize-1;
	cout << "Введите 5 цифр числа через пробел начиная с большего разряда\n";
	for (i = maxsize - 1; i >= 0; i--) {
		cin >> a[i];
	}
}
void diffOfArrays(int a[], int b[], int res[]) {
	int i = 0;
	while (i < maxsize) {
		if (a[i] >= b[i]) res[i] = a[i] -b[i];
		else { a[i + 1] -= 1; a[i] += 10; res[i] = a[i] - b[i];}
		i++;
	}
}
void sumOfArrays(int a[], int b[],int res[]) {
	int i = 0, t = 0;
	while (i < maxsize) {
		res[i] = a[i] + b[i] + t;
		t = res[i] / 10;
		res[i] %= 10;
		i++;
	}
}
//void fibon(int a[],int b[],int res[]) {
//	int i = 2, t = 0; res[0] = 0; res[1] = 1;
//		while (i <= maxsize)
//		{
//			a[i - 2] = res[i - 2];
//			b[i - 2] = res[i - 1];
//			res[i] = a[i-2] + b[i-2] + t;
//			t = res[i] / 10;
//			res[i] = res[i] % 10;
//				i++;
//	
//		}
//	}
int main()
{
	setlocale(LC_ALL, "russian");
	int a[maxsize], b[maxsize], res[maxsize+1];
	int init = 0;
	/*initArray(a, init);
	initArray(b, init);
	printNumber(a);
	printNumber(b);
	sumOfArrays(a, b, resOfSum);
	printNumber(resOfSum);*/
	inputArray(a);
	printNumber(a);
	inputArray(b);
	printNumber(b);
	diffOfArrays(a, b, res);
	cout <<"разность двух введенных чисел равна:";
	printNumber(res);
	sumOfArrays(a, b, res);
	cout << "сумма двух введенных чисел равна:";
	printNumber(res);
	//fibon(a, b,res);
	printNumber(res);
	system("pause");
}