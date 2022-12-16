#include "Worker.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор без параметров
Staff::Staff()
{
    FIO = "";
    status = "";
    pay = 0;
    cout << "Constructor bez parametrov dlia objecta" << this << endl;
}
//конструктор с параметрами
Staff::Staff(string N, string K, double S)
{
    FIO = N;
    status = K;
    pay = S;
    cout << "Constructor s parametrami dlia objecta" << this << endl;
}
//конструктор копирования
Staff::Staff(const Staff &t)
{
    FIO = t.FIO;
    status = t.status;
    pay = t.pay;

    cout << "Constructor copirovania dlia objecta" << this << endl;
}
//деструктор
Staff::~Staff()
{
    cout << "Destructor dlia objecta" << this << endl;
}
//селекторы
string Staff::get_FIO()
{
    return FIO;
}
string Staff::get_status()
{
    return status;
}
double Staff::get_pay()
{
    return pay;
}
//модификаторы
void Staff::set_FIO(string N)
{
    FIO = N;
}
void Staff::set_status(string K)
{
    status= K;
}
void Staff::set_pay(double S)
{
    pay = S;
}
//метод для просмотра атрибутов
void Staff::show()
{
    cout << "naimenovanie :" << FIO << endl;
    cout << "kolichestvo :" << status << endl;
    cout << "stoimost :" << pay << endl;
}
