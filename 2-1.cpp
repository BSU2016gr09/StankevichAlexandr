#include<iostream> //������ ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� 1 �� N. "�����������" ������ (��������� ������� ������ ������, 1-� ������ ���������, 2-� ���������� � ������������� � �.�.) ��������� ������ ��������� N.
#include<clocale>
#include<time.h>
using std::cout; using std::cin; using std::swap;
void printarray(int a[], int N) { //����� ������� �������� N ��������
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void rollarray(int a[], int N) { //"��������������" ������.
	int i = 0;
	while (i < N / 2) { //��� N �������� ������ ���������� ������� �����-��:)
		swap(a[i], a[N - 1 - i]);
		i++;
	}
}
void fillarray(int N, int a[]) { //���������� ������� ���������� ������� �� ���������� (1,N)
	int i = 0;
	while (i<N) {
		a[i] = rand() % (N + 1);
		i++;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 9;
	int a[N];
	fillarray(N, a);
	cout << "������: ";
	printarray(a, N);
	rollarray(a, N);
	cout << "������������ ������: ";
	printarray(a, N);
	system("pause");
}