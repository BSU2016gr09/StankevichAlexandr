#include<clocale>
#include<iostream>
using std::cout; using std::cin;
const int N=4;
void includeToQueue(float queue[], int N, int&end, int elem){
	end = (end + 1) % N;
	queue[end] = elem;
}
int getFromQueue(float queue[], int N, int&start) {
	start = (start + 1) % N;
	return queue[start];
}
void printQueue(float queue[],int k) {
	int i = 0;
	while (i < k) {
		cout << queue[i] << " ";
		i++;
	}
}
	int main() {
		setlocale(0, "");
		int start = -1, end = -1, elem, k;
		float queue[N];
		cout << "У нас есть пустая очередь\n Добавим в нее три элемента\n Введите 3 числа:\n";
		k = N-1;
		while (k > 0) {
			cin >> elem;
			includeToQueue(queue, N, end, elem); k--;
		}
		k=N-1;
		cout << "Полученная очередь:\n";
		printQueue(queue,k);
		cout << "\nУдалим два элемента из очереди";
		cout << "\nДобавим в очередь снова три элемента\n Введите 3 числа:\n";
		while (k > 0) {
			cin >> elem;
			includeToQueue(queue, N, end, elem); k--;
		}
		k = N;
		cout << "Полученная очередь:\n";
		printQueue(queue,k);
		system("pause");
	}