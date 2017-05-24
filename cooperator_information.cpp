//Определить объект: информация о сотруднике:год рождения, оклад, табельный номер струдника и его фамилию.
//Составить функции:
//1.определение сотрудника с максимальной з/п
//2.сортировка сотрудников по возрасту
//3.определение средне з/п сотрудника???? у нас же есть просто з/п, как можно вычислить среднюю?


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <clocale>
#include <algorithm>

using namespace std;

class CooperatorInf{ 

	friend ostream& operator<<(ostream&, const CooperatorInf&);
	friend istream& operator>>(istream&, CooperatorInf&);
	friend CooperatorInf maxSalaryCoop(CooperatorInf*, int);
	friend CooperatorInf yearSort(CooperatorInf*, int);
//	friend void giveMemory(char*, int);

private:

	int tableNumber;
	char *surname;
	int bornYear;
	int salary;

public:

	CooperatorInf() {//конструктор по умолчанию
		surname = nullptr;
		tableNumber = salary = bornYear = 0;
		giveMemory(surname, 20);
	}

	CooperatorInf(char* surname, int bornYear) {//конструктор с параметрами
		giveMemory(this->surname, 20);
		strcpy(this->surname,surname);
		this->bornYear = bornYear;
	}

	CooperatorInf(char* surname, int bornYear, int tableNumber, int salary){ //конструктор с параметрами
		giveMemory(this->surname, 20);
		strcpy(this->surname, surname);
		this->bornYear = bornYear;
		this->salary = salary;
		this->tableNumber = tableNumber;

	}

	CooperatorInf(int tableNumber,int salary){ //конструктор с параметрами
		this->salary = salary;
		this->tableNumber - tableNumber;
	}

	CooperatorInf(const CooperatorInf &obj){ //конструктор копирования
		this->surname = nullptr;
		this->salary = 0;
		this->tableNumber = 0;
		this->bornYear = 0;
		giveMemory(this->surname, 20);
		strcpy(this->surname,obj.surname);
		this->salary = obj.salary;
		this->tableNumber = obj.tableNumber;
		this->bornYear = obj.bornYear;
	}

	~CooperatorInf() {//деструктор
		delete[] surname;
	}

	void giveMemory(char* &arr, int N){//функция выделения памяти
		try{
			arr = new char[N];
		}
		catch (...){
			cout << "Not enough memory";
		}
	}
  
	CooperatorInf& operator=(CooperatorInf&obj){ //оператор =
		strcpy(this->surname, obj.surname);
		this->salary = obj.salary;
		this->tableNumber = obj.tableNumber;
		this->bornYear = obj.bornYear;
		return *this;
	}

	//геттеры сеттеры
	   
	void setSurname(char *surname) {strcpy(this->surname,surname); }
	void setSalary(int salary) { this->salary = salary; }
	void setBornYear(int bornYear) { this->bornYear= bornYear; }
	void setTableNumber(int tableNumber) { this->tableNumber = tableNumber; }

	char* getSurname() { return (*this).surname; }
	int getSalary() { return (*this).salary; }
	int getBornYear() { return (*this).bornYear; }
	int getTableNumber() { return (*this).tableNumber; }
	
	//геттеры сеттеры

	



};

ostream& operator<<(ostream& print, const CooperatorInf& coop) //перегрузка вывода
{
	print << coop.surname << " " << coop.bornYear << "года рождения, табельный номер:" << coop.tableNumber << ", зарплата: " << coop.salary << "руб.\n";
	return print;
}

istream& operator>>(istream& input, CooperatorInf& coop)	//перегрузка ввода
{
	input.getline(coop.surname,strlen(coop.surname));
	input >> coop.bornYear;
	input >> coop.tableNumber;
	input >> coop.salary;
	return input;
}

CooperatorInf maxSalaryCoop(CooperatorInf*cooperators,int N){ //функция определения сотрудника с максимальной заработной платой
	int sort = cooperators[0].salary, i = 0;
	while (i < N){
		if (cooperators[i].salary > sort) sort = cooperators[i].salary;
		i++;
	}
	return cooperators[--i];
}

CooperatorInf yearSort(CooperatorInf*cooperators, int N){ //функция сортировки сотрудников по возрасту(по возрастанию)
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (cooperators[j].bornYear > cooperators[j + 1].bornYear) swap(cooperators[j],cooperators[j + 1]);
		}
	}
	return *cooperators;
}

void main(){
	setlocale(0, "");
	int N;
	CooperatorInf coop1,coop2("John",1980,13,1000),coop3;
	cin >> coop1;
	cin.ignore();
	cin>> coop3;
	CooperatorInf cooperators[3];
	cooperators[0] = coop1;
	cooperators[1] = coop2;
	cooperators[2] = coop3;
	cout << "\n" <<"Максимальная зарплата у сотрудника "<< maxSalaryCoop(cooperators, 3) << "\n";
	yearSort(cooperators, 3);
	for (int i = 0; i < 3; i++){
		cout << cooperators[i] << "\n";
	}
	system("pause");

}




