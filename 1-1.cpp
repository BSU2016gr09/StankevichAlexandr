#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
int DigitSum(int n) { //����� ���� ���������� �����
	int i = 0, k = 0;
	while (i < n) {
		k = k + (n % 10);
		n /= 10;
	}
	return k;
}
int main()//"������������ ������ � ���������� ����������� �����, ��������� ������������ �����, ��������� � ������� �� ����� ����� ���� ��������� ������������� �����.
{
	setlocale(0, "");
	cout << "������������ ������ � ���������� ����������� �����, ��������� ������������ �����, ��������� � ������� �� ����� ����� ���� ��������� ������������� �����.\n";
	cout << "������� ����������� �����\n";
	float n;
	cin >> n;
	if (n / floor(n) == 1 && n > 0) {
		cout << DigitSum(n) << "\n";
	}
	else cout << "�������� ����\n";
	system("pause");
}