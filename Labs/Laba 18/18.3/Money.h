#include <iostream>
using namespace std;

class Money
{
    long RUB;
    int kop;

public:
    Money()
    {
        RUB = 0;
        kop = 0;
    };
    Money(long m, int s)
    {
        RUB = m;
        kop = s;
    }
    Money(const Money &t)
    {
        RUB = t.RUB;
        kop = t.kop;
    }
    ~Money(){};
    int get_RUB()
    {
        return RUB;
    }
    int get_kop()
    {
        return kop;
    }
    void set_RUB(long m)
    {
        RUB = m;
    }
    void set_kop(int s)
    {
        kop = s;
    }
    //перегруженные операции
    Money &operator=(const Money &);
    Money &operator++();
    Money operator++(int); //постфиксная операция
    Money operator+(const Money &);
    //глобальные функции ввода-вывода
    friend istream &operator>>(istream &in, Money &t);
    friend ostream &operator<<(ostream &out, const Money &t);
};
