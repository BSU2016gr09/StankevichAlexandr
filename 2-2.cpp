#include<iostream> //������ ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� -N �� N. ���������� �������� �������� ������� ������ �� 1 ������� (��������� ������� ������ ������, 1-� ������ 2-�, 2-� ������ 3-� � �.�.) ����� ���������� �������� �������� ������� ����� �� 1 ������� (������ ������� ������ ���������, 2-� ������ 1-� � �.�)
#include<clocale>
#include<time.h>
using std::cout; using std::cin; using std::swap;
void printarray(int a[], int N) { //����� ������� �������� n ��������
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void fillarray(int a[], int N) { //���������� ������� ������� �� ���������� (-N,N)
	int i = 0;
	int min = -N, max = N;
	while (i<N) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void shiftarrayright(int a[], int N) { //����� ������� ������ �� ���� �������
	int k, i = 1;
	k = a[N - 1];
	i = N - 1;
	while (i >0) {
		a[i] = a[i - 1];
		i--;
	}
	a[0] = k;
}
void shiftarrayleft(int a[], int N) { //����� ������� ����� �� ���� �������
	int k, i = 1;
	k = a[0];
	while (i <N - 1) {
		a[i] = a[i + 1];
		i++;
	}
	a[N - 1] = k;
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 10;
	int a[N];
	fillarray(a, N);
	cout << "�������� ������: ";
	printarray(a, N);
	shiftarrayright(a, N);
	cout << "��������� ������ �� ���� ������� ������: ";
	printarray(a, N);
	shiftarrayleft(a, N);
	cout << "��������� ����� �� ���� ������� ������: ";
	printarray(a, N);
	system("pause");
}