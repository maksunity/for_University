#pragma once
#include "object.h"
#include <string>
#include <iostream>
using namespace std;
class Car:
public Object
{
public:
    Car(void);
public:
    virtual ~Car(void);
    void Show(); //функция для просмотра атрибутов класса с помощью указателя 
    Car(int,int,int);
    Car(const Car &);
    int Get_mark()
    {
        return mark;
    }
    int Get_cyl()
    {
        return cyl;
    }
    int Get_power()
    {
        return power;
    }
    void Set_mark(int);
    void Set_cyl(int);
    void Set_power(int);
    Car &operator=(const Car &);
    friend istream &operator>>(istream &in, Car &c);
    friend ostream &operator<<(ostream &out, const Car &c);

protected:
    int mark;
    int cyl;
    int power;
};
