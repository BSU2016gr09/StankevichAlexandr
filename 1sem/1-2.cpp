#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
int MaxOfDigits(int n) { //наибольший из возможных с такими же цифрами
	int i = 0, c = 0, j;
	int a[5];//Плохое имя!!!
	while (n != 0) {
		a[i] = n % 10;
		i++; n /= 10;
	}
	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 5)
		{
			if (a[i] > a[j]) swap(a[i], a[j]);
			j++;
		}
		i++;
	}
	n = a[4] * 10000 + a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];//если ты уже в цикле находил цифры, то в цикле надо и рассчитывать число n
	return n;
}
int main()//"Пользователь вводит с клавиатуры пятизначное натуральное число, которое сохраняется в переменную n, проверить корректность ввода, составить и вывести на экран число из цифр введённого числа n, так, чтобы выведенное число оказалось максимальным из возможных. Например, если пользователь ввёл число 22195, то программа должна вывести число 95221.
{
	setlocale(0, "");
	cout << "Пользователь вводит с клавиатуры пятизначное натуральное число, которое сохраняется в переменную n, проверить корректность ввода, составить и вывести на экран число из цифр введённого числа n, так, чтобы выведенное число оказалось максимальным из возможных. Например, если пользователь ввёл число 22195, то программа должна вывести число 95221.\n";
	cout << "введите натуральное пятизначное число\n";
	float n;  //почему float?
	cin >> n;
	if (n / floor(n) == 1 && n > 0 && n < 99999 && n>9999) {
		cout << MaxOfDigits(n) << "\n";
	}
	else cout << "Неверный ввод\n";
	system("pause");
}