#include <iostream>
#include <cmath>
#include <time.h>
#include <clocale>
using namespace std;
void FillArray(int n, int a[], int min, int max) { //Именя снова с БОЛЬШОЙ буквы//çàïîëíåíèå ìàññèâà ÷èñëàìè èç ïðîìåæóòêà (min,max)
	int i = 0;
	while (i<n) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void PrintElementsWithOddNumbers(int&n, int a[]) { //Зачем передавать n по ссылке//ââûâîä ýëåìåíòîâ ìàññèâà ñ íå÷åòíûìè íîìåðàìè
	cout << "×èñëà ñ íå÷åòíûìè íîìåðàìè:";
	while (n < 99) {//что за константа 99????? Надо N
		cout << a[n] << " ";
		n += 2;
	}
}
void PrintElementsWithEvenNumbers(int&n, int a[]) { //Зачем передавать n по ссылке//ââûâîä ýëåìåíòîâ ìàññèâà ñ ÷åòíûìè íîìåðàìè
	cout << "×èñëà ñ ÷åòíûìè íîìåðàìè:";
	while (n < 99) {//что за константа 99????? Надо N
		cout << a[n] << " ";
		n += 2;
	}
}
int main()//Îáúÿâèòü ìàññèâ âåùåñòâåííûõ ÷èñåë ðàçìåðà N (÷èñëî N îáúÿâèòü êàê êîíñòàíòó). Ïðîèíèöèàëèçèðîâàòü çíà÷åíèÿ ýëåìåíòîâ ìàññèâà ñëó÷àéíûìè ÷èñëàìè èç ïðîìåæóòêà îò -50 äî 50. Âûâåñòè çíà÷åíèÿ ñíà÷àëà ýëåìåíòîâ ñ íå÷åòíûìè êîýôôèöèåíòàìè (1-é, 3-é, 5-é,...) à çàòåì - ñ ÷åòíûìè.
{
	int n;
	srand(time(0));
	setlocale(0, "");
	cout << "Îáúÿâèòü ìàññèâ âåùåñòâåííûõ ÷èñåë ðàçìåðà N (÷èñëî N îáúÿâèòü êàê êîíñòàíòó). Ïðîèíèöèàëèçèðîâàòü çíà÷åíèÿ ýëåìåíòîâ ìàññèâà ñëó÷àéíûìè ÷èñëàìè èç ïðîìåæóòêà îò -50 äî 50. Âûâåñòè çíà÷åíèÿ ñíà÷àëà ýëåìåíòîâ ñ íå÷åòíûìè êîýôôèöèåíòàìè (1-é, 3-é, 5-é,...) à çàòåì - ñ ÷åòíûìè.\n";
	const int k = 100;//по условию задачи эта перемнная называется N
	int a[k];
	FillArray(k, a, -50, 50);
	n = 1;
	PrintElementsWithOddNumbers(n, a);
	n = 0;
	PrintElementsWithEvenNumbers(n, a);
	system("pause");
}
