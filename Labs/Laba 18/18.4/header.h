class Triada
{
public:
    Triada(void);

public:
    ~Triada(void);
};

#pragma once
#include <string>
#include <iostream>
using namespace std;
class Triada
{
    //конструктор без параметров
public:
    Triada(void);

public:
    //деструктор
    virtual ~Triada(void);
    //констрктор с параметрами
    Triada(int, int, int);
    //конструктор копирования
    Triada(const Triada &);

    //селекторы
    int Get_first()
    {
        return first;
    }
    int Get_second()
    {
        return second;
    }
    int Get_third()
    {
        return third;
    }
    //модификаторы
    void Set_first(int);
    void Set_second(int);
    void Set_third(int);
    //перегрузка операции присваивания
    Triada &operator=(const Triada &);
    //глобальные операторы-функции ввода-вывода
    friend istream &operator>>(istream &in, Triada &c);
    friend ostream &operator<<(ostream &out, const Triada &c);
    //атрибуты protected:
    int first;
    int second;
    int third;
};
