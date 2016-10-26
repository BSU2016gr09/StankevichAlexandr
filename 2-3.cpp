#include<iostream> //Ìàññèâ À öåëûõ ÷èñåë ðàçìåðà N ïðîèíèöèàëèçèðîâàòü ñëó÷àéíûìè ÷èñëàìè èç ïðîìåæóòêà îò -N äî N. Íå èñïîëüçóÿ ôóíêöèè èç çàäà÷è 2-2 Íàïèñàòü ôóíêöèè öèêëè÷åñêîãî ñäâèíãà ýëåìåíòû ìàññèâà âïðàâî íà k ýëåìåíòîâ (1-é ñòàíåò 1+k -ûì, 2-é ñòàíåò 2+k -ûì è ò.ä.) è âëåâî íà k ýëåìåíòîâ. Â main íàïèñàòü âûçîâ ýòèõ ôóíêöèé äëÿ ÷èñëà k, êîòîðîå ââîäèò ïîëüçîâàòåëü.
#include<clocale>
#include<time.h>
using std::cout; using std::cin;
void fillarray(int a[], int N) { //çàïîëíåíèå ìàññèâà ÷èñëàìè èç ïðîìåæóòêà (-N,N)
	int i = 0;
	int min = -N, max = N;
	while (i<N) {
		a[i] = rand() % (max + 1 - min) + min;
		i++;
	}
}
void printarray(int a[], int N) { //âûâîä ìàññèâà ðàçìåðîì N ñèìâîëîâ
	int i = 0;
	while (i < N) {
		cout << a[i] << " ";
		i++;
	}
	cout << "\n";
}
void shiftarrayleft(int a[], int N, int k) { //ñäâèãàåì ìàññèâ íà k ýëåìåíòîâ âëåâî
	int i = 1, c = 0, j;
	for (c = 0; c < k; c++) {
		j = a[0];
		for (i = 1; i<N; i++) //совсем плохой метод!!!!! Ты фактически сдвигаешь не на k позиций, а k раз на 1 позицию. Это в Л раз больше работы чем надо!!!!!
		{
			a[i - 1] = a[i];
		}
		a[N - 1] = j;
	}
}
void shiftarrayright(int a[], int N, int k) { //ñäâèãàåì ìàññèâ íà k ýëåìåíòîâ âïðàâî
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
	cout << "Ââåäèòå íà ñêîëüêî ñäâèíóòü ìàññèâ âïðàâî\n";
	cin >> k;
	fillarray(a, N);
	cout << "Èñõîäíûé ìàññèâ: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayleft(a, N, k);
	cout << "Ìàññèâ ñäâèíóòûé âëåâî íà " << k << " ïîçèöèé: ";
	printarray(a, N);
	cout << "\n\n";
	shiftarrayright(a, N, k);
	cout << "Ìàññèâ ñäâèíóòûé âïðàâî íà " << k << " ïîçèöèé: ";
	printarray(a, N);
	cout << "\n\n";
	system("pause");
}
