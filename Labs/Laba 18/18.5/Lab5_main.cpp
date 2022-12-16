#include "Object.h"
#include "Triada.h"
#include <string>
#include <iostream>
#include "Lorry.h"
#include "Vector.h"
using namespace std;
void main()
{
    Car a;
    cin >> a;
    cout << a << endl; //вывод с помощью перегруженной операции
    Object *p = &a;
    p->Show(); //вывод с помощью метода Show() и указателя
    /*Lorry b;
    cin >> b;
    cout << b << endl; //вывод с помощью перегруженной операции
    p = &b;
    p->Show(); //вывод с помощью метода Show() и указателя*/

    Vector v(5); //вектор из 5 элементов
    Car a;       //объект класса Car
    cin >> a;
    Lorry b; // объект класса
    Lorry cin >> b;
    Object *p = &a; //ставим указатель на объект класса
    Car v.Add(p);   //добавляем объект в вектор
    p = &b;         //ставим указатель на объект класса
    Lorry v.Add(p); //добавляем объект в вектор
    cout << v;      //вывод вектора
}
