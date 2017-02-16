#include <iostream> //Напишите игру в кости между человеком и компьютером. Они по очереди кидают по два кубика. Побеждает тот у кого сумма больше. Игра заканчивается если набрана сумма >50. Кубики рисуйте в отдельной ф-ции псевдографикой.
#include <time.h>
using std::cout; using std::cin;
void randomvalue(int&first, int&second) { //получение случайных значений для первого и второго кубика
	first = rand() % 6 + 1;
	second = rand() % 6 + 1;
}
void printresult(int value) { //вывод костей псевдографикой
	switch (value)
	{
	case 1:
		cout << "---------" << "\n";
		cout << "|       |" << "\n";
		cout << "|   o   |" << "\n";
		cout << "|       |" << "\n";
		cout << "---------" << "\n";
		break;
	case 2:
		cout << "---------" << "\n";
		cout << "|       |" << "\n";
		cout << "| o   o |" << "\n";
		cout << "|       |" << "\n";
		cout << "---------" << "\n";
		break;
	case 3:
		cout << "---------" << "\n";
		cout << "| o     |" << "\n";
		cout << "|   o   |" << "\n";
		cout << "|     o |" << "\n";
		cout << "---------" << "\n";
		break;
	case 4:
		cout << "---------" << "\n";
		cout << "| o   o |" << "\n";
		cout << "|       |" << "\n";
		cout << "| o   o |" << "\n";
		cout << "---------" << "\n";
		break;
	case 5:
		cout << "---------" << "\n";
		cout << "| o   o |" << "\n";
		cout << "|   o   |" << "\n";
		cout << "| o   o |" << "\n";
		cout << "---------" << "\n";
		break;
	case 6:
		cout << "---------" << "\n";
		cout << "| o   o |" << "\n";
		cout << "| o   o |" << "\n";
		cout << "| o   o |" << "\n";
		cout << "---------" << "\n";
		break;
	}
}
void sump(int first, int second, int&sumplayer) { //подсчет суммы для игрока
	sumplayer = sumplayer + second + first;
	cout << "У тебя выпало:" << first + second << "\n\n";
}
void sumc(int first, int second, int&sumcomp) { //подсчет суммы для компьютера
	sumcomp = sumcomp + second + first;
	cout << "У компьютера выпало:" << first + second << "\n\n";
}
int main() //Напишите игру в кости между человеком и компьютером. Они по очереди кидают по два кубика. Побеждает тот у кого сумма больше. Игра заканчивается если набрана сумма >50. Кубики рисуйте в отдельной ф-ции псевдографикой.
{
	int first = 0, second = 0, sumplayer = 0, sumcomp = 0;
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	while (sumplayer <= 50 && sumcomp <= 50) {
		cout << "Нажми ENTER чтобы бросить кости\n";
		getchar();
		randomvalue(first, second);
		sump(first, second, sumplayer);
		printresult(first);
		printresult(second);
		cout << "У тебя в сумме " << sumplayer << " баллов\n\n";
		randomvalue(first, second);
		sumc(first, second, sumcomp);
		printresult(first);
		printresult(second);
			cout << "У компьютера в сумме " << sumcomp << " баллов\n\n";
	}
	if (sumplayer > sumcomp) cout << "Вы выйграли!!\n\n";
	else if (sumplayer < sumcomp) cout << "К сожалению вы проиграли:(\n\n";
	else cout << "Ничья!\n\n";
	system("pause");
}
