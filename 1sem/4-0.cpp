#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	float x = -6, b;
	while (x < 6) {
		if (x == 0) b = 2; else b = (sin(2*x) / x) * 45;
		cout << right << setw(b + 40) << '*' << "\n";
		x += 0.1;
	}
	system("pause");
}
