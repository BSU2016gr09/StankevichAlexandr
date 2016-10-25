#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
void FillArray(int n, int a[], int min, int max) { //���������� ������� ������� �� ���������� (min,max)
	int i = 0;
	while (i<n) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void PrintElementsWithOddNumbers(int&n, int a[]) { //������ ��������� ������� � ��������� ��������
	cout << "����� � ��������� ��������:";
	while (n < 99) {
		cout << a[n] << " ";
		n += 2;
	}
}
void PrintElementsWithEvenNumbers(int&n, int a[]) { //������ ��������� ������� � ������� ��������
	cout << "����� � ������� ��������:";
	while (n < 99) {
		cout << a[n] << " ";
		n += 2;
	}
}
int main()//�������� ������ ������������ ����� ������� N (����� N �������� ��� ���������). ������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50. ������� �������� ������� ��������� � ��������� �������������� (1-�, 3-�, 5-�,...) � ����� - � �������.
{
	int n;
	srand(time(0));
	setlocale(0, "");
	cout << "�������� ������ ������������ ����� ������� N (����� N �������� ��� ���������). ������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50. ������� �������� ������� ��������� � ��������� �������������� (1-�, 3-�, 5-�,...) � ����� - � �������.\n";
	const int k = 100;
	int a[k];
	FillArray(k, a, -50, 50);
	n = 1;
	PrintElementsWithOddNumbers(n, a);
	n = 0;
	PrintElementsWithEvenNumbers(n, a);
	system("pause");
}