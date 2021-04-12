#include "header.h"
Triada::Triada(void)
{
}
Triada::~Triada(void)
{
}

#include "header.h"
//конструктор без параметров
Triada::Triada(void)
{
    first = 0;
    second = 0;
    third = 0;
}
//деструктор
Triada::~Triada(void)
{
}
//конструктор с параметрами
Triada::Triada(int M, int C, int P)
{
    first = M;
    second = C;
    third = P;
}
//конструктор копирования
Triada::Triada(const Triada &Triada)
{
    first = Triada.first;
    second = Triada.second;
    third = Triada.third;
}
//модификаторы
void Triada::Set_second(int C)
{
    second = C;
}
void Triada::Set_first(int M)
{
    first = M;
}

void Triada::Set_third(int P)
{
    third = P;
}
//перегрузка операции присваивания
Triada &Triada::operator=(const Triada &c)
{
    if (&c == this)
        return *this;
    first = c.first;
    third = c.third;
    second = c.second;
    return *this;
}
//глобальная функция для ввода
istream &operator>>(istream &in, Triada &c)
{
    cout << "\n first:";
    in >> c.first;
    cout << "\n second:";
    in >> c.third;
    cout << "\n third:";
    in >> c.second;
    return in;
}
//глобальная функция для вывода
ostream &operator<<(ostream &out, const Triada &c)
{
    out << "\nfirst : " << c.first;
    out << "\nsecond : " << c.second;
    out << "\nthird : " << c.third;
    out << "\n";
    return out;
}
