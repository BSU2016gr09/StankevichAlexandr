#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
void IsPositiveOrNegative(int a[], int b[], int c[], int n, int&j, int&l) { //���������� � ��� �������: � �������������� ������� � � ��������������
	int i = 0;
	while (i < n) {
		if (a[i] > 0) {
			b[j] = a[i]; j++;
		}
		else if (a[i] < 0) {
			c[l] = a[i]; l++;
		}
		i++;
	}
}
void PrintArray(int a[], int n) { //����� ������� �������� n ��������
	int i = 0;
	while (i < n) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void FillArray(int n, int a[], int min, int max) { //���������� ������� ������� �� ���������� (min,max)
	int i = 0;
	while (i<n) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}

}
int main()//�������� ������ � ������������ ����� ������� N (����� N �������� ��� ���������). ������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50. ��������� ������ � �� ��� �������: ������������� �������� � ������ �, ������������� - � �.
{
	srand(time(0));
	setlocale(0, "");
	cout << "�������� ������ � ������������ ����� ������� N (����� N �������� ��� ���������). ������������������� �������� ��������� ������� ���������� ������� �� ���������� �� -50 �� 50. ��������� ������ � �� ��� �������: ������������� �������� � ������ �, ������������� - � �.\n";
	const int n = 100;
	int a[n], b[n], c[n], j = 0, l = 0;
	FillArray(n, a, -50, 50);
	IsPositiveOrNegative(a, b, c, n, j, l);
	cout << "������������� �������� �������: ";
	PrintArray(b, j);
	cout << "\n" << "������������� �������� �������: ";
	PrintArray(c, l);
	system("pause");
}
