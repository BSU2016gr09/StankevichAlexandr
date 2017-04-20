#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;

//Доделать (учитывая мои комментарии в ваших репозиториях) свои проекты с дополнительной реализацией конструкторов, 
//деструкторов (в которых, просто выдается сообщение, что он сработал) и операций =, +,- тех простейших классов, которые вы делали к 6.04
//В main() надо не только объявить 2 - 3 объекта вашего класса, но и сделать пару - тройку указателей на объеты!!!
//Проинициализировать некоторые из них теми объетами, которые уже есть, а некоторые проинициализировать с помощью оператора, NEW.
//После этого, в main выполнить пару - тройку действий с объектами и с указателями(присвоение, сумма, удаление...)
//чтобы показать, что все методы работают!


class Equation{ //решение возвратного кубичского уравнения (Ax^3+Bx^2+Bx+A)

public:

	Equation() {//конструктор по умолчанию
		a = 0; b = 0; 
	}

	Equation(double a, double b) {//конструктор по умолчанию
		this->a = a;
		this->b = b;
	}

	~Equation() {//деструктор по умолчанию
	}
	
	Equation& operator +(Equation&x){//оператор сложения
		this->a += x.a;
		this->b += x.b;
		return *this;
	}

	Equation& operator -(Equation&x){//оператор вычитания
		this->a -= x.a;
		this->b -= x.b;
		return *this;
	}

	Equation& operator =(Equation&x){//оператор "равно"
		this->a = x.a;
		this->b = x.b;
		return *this;
	}

	Equation& operator *(Equation&x){//оператор умножения
		this->a *= x.a;
		this->b *= x.b;
		return *this;
	}

	Equation& operator /(Equation&x){//оператор деления
		this->a /= x.a;
		this->b /= x.b;
		return *this;
	}

	void setA(double a) {    //геттеры сеттеры
		this->a = a;
	}
	void setB(double b) {
		this->b = b;
	}
	double getA() {
		return (*this).a;
	}
	double getB() {
		return (*this).b;
	}                        //геттеры сеттеры

	void printEquation(){//метод вывода возвратного кубического уравнения
		cout << a << "x^3+" << b<<"x^2+"<<b<<"x+"<<a<< "\n";
	}

	void rootOfEquation(){//метод нахождения корней возвратного кубического уравнения
		double discr;
		cout << "x1=-1" << "\n";
		discr = (b - a)*(b - a) - 4 * a*a;
		if (discr < 0);
		else{
			cout << "x2=" << ((a - b) - sqrt(discr)) / (2 * a) << "\n";
			cout << "x3=" << ((a - b) + sqrt(discr)) / (2 * a) << "\n";
		}
	}

private:
	double a, b;

};

void giveMemory(Equation * &tmp) {
	try {
		tmp = new Equation;
	}
	catch (...) {
		cout << "Not enough memory\n";
		system("pause");
	}
}


void deleteMemory(Equation * &tmp) {
	delete tmp;
	tmp = nullptr;
}

void main(){
	Equation equation1;
	equation1.printEquation();
	equation1.rootOfEquation();
	cout << "\n\n";

	Equation equation2(3,8);
	equation2.printEquation();
	equation2.rootOfEquation();
	cout << "\n\n";

	Equation equation3;
	equation3.setA(10);
	equation3.setB(7);
	equation3.printEquation();
	equation3.rootOfEquation();
	cout << "\n\n";

	Equation equation4(4, 1);
	cout << "a=" << equation4.getA() << "\n";
	cout << "b=" << equation4.getB() << "\n";
	equation4.rootOfEquation();
	cout << "\n\n";

	Equation equation5;
	equation5.setA(equation2.getA() + 7);
	equation5.setB(equation3.getB() - 1);
	equation5.printEquation();
	equation5.rootOfEquation();
	cout << "\n\n";

	Equation* equation6;
	giveMemory(equation6);
	*equation6 = equation4 - equation2;
	equation6->printEquation();
	equation6->rootOfEquation();
	deleteMemory(equation6);
	cout << "\n\n";

	system("pause");

}




