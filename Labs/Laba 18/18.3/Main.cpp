#include "Money.h"
#include <iostream>
using namespace std;

void main()
{
    Money a;                    //конструктор без параметров
    Money b;                    //конструктор без параметров
    Money c;                    //конструктор без параметров
    cin >> a;                  //ввод переменной
    cin >> b;                  //ввод переменной
    ++a;                       //префиксная операция инкремент
    cout << a << endl;         //вывод переменной
    c = (a++) + b;             //сложение и постфиксная операция инкремент
    cout << "Money: " << a; //вывод переменной
    cout << ", " << b << endl; //вывод переменной
    cout << "Sravnenie: " << c << endl; //вывод переменной
}
