#include "Money.h"
#include <iostream>
using namespace std;
//перегрузка операции присваивания
Money &Money::operator=(const Money &t)
{
    //проверка на самоприсваивание
    if (&t == this)
        return *this;
    RUB = t.RUB;
    kop = t.kop;
    return *this;
}
//перегрузка префиксной операции инкремент
Money &Money::operator++()
{
    int temp = RUB * 100 + kop;
    temp++;
    RUB = temp;
    kop = temp / 100;
    return *this;
}
//перегрузка постфиксной операции инкремент
Money Money::operator++(int)
{
    int temp = RUB * 100 + kop;
    temp++;
    Money t(RUB, kop);
    RUB = temp ;
    kop = temp / 60;
    return t;
}
//перегрузка бинарной операции сложения
Money Money::operator+(const Money &t)
{
    int temp1 = RUB * 100 + kop;
    int temp2 = t.RUB * 60 + t.kop;
    Money p;
    p.RUB = (temp1 + temp2);
    p.kop = (temp1 + temp2) /100;
    return p;
}

//перегрузка глобальной функции-операции ввода
istream &operator>>(istream &in, Money &t)
{
    cout << "min?";
    in >> t.RUB;
    cout << "sec?";
    in >> t.kop;
    return in;
}
//перегрузка глобальной функции-операции вывода
ostream &operator<<(ostream &out, const Money &t)
{

    return (out << t.RUB << " : " << t.kop);
}
