#include<iostream> //������ � ����� ����� ������� N ������������������� ���������� ������� �� ���������� �� -N �� N. �� ��������� ������� �� ������ 2-2 �������� ������� ������������ ������� �������� ������� ������ �� k ��������� (1-� ������ 1+k -��, 2-� ������ 2+k -�� � �.�.) � ����� �� k ���������. � main �������� ����� ���� ������� ��� ����� k, ������� ������ ������������.
#include<clocale>
#include<time.h>
using std::cout; using std::cin;
void fillarray(int a[], int N) { //���������� ������� ������� �� ���������� (-N,N)
	int i = 0;
	int min = -N, max = N;
	while (i<N) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void printarray(int a[], int N) { //����� ������� �������� N ��������
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void shiftarrayleft(int a[], int N, int k) { //�������� ������ �� k ��������� �����
	int i = 1, c = 0, j;
	for (c = 0; c < k; c++) {
		j = a[0];
		for (i = 1; i<N; i++)
		{
			a[i - 1] = a[i];
		}
		a[N - 1] = j;
	}
}
void shiftarrayright(int a[], int N, int k) { //�������� ������ �� k ��������� ������
	int j, i, c;
	for (c = 0; c < k; c++) {
		j = a[N - 1];
		for (i = N - 1; i > 0; i--)
			a[i] = a[i - 1];
		a[0] = j;
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");
	const int N = 10;
	int a[N], newarray[N], k;
	cout << "������� �� ������� �������� ������ ������\n";
	cin >> k;
	fillarray(a, N);
	cout << "�������� ������: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayleft(a, N, k);
	cout << "������ ��������� ����� �� " << k << " �������: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayright(a, N, k);
	cout << "������ ��������� ������ �� " << k << " �������: ";
	printarray(a, N);
	cout << "\n\n";
	system("pause");
}