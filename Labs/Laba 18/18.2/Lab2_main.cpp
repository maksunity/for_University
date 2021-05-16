#include "Worker.h"
#include <iostream>
#include <string>
using namespace std;
//функция для возврата объекта как результата
Staff make_Staff()
{
    string s;
    string i;
    double d;
    cout << "Vvedite naimenovanie: ";
    cin >> s;
    cout << "Vvedite kolichestvo: ";

    cin >> i;
    cout << "Vvedite stoimost: ";
    cin >> d;
    Staff t(s, i, d);
    return t;
}
//функция для передачи объекта как параметра
void print_Staff(Staff t)
{
    t.show();
}
void main()
{
    //конструктор без параметров
    Staff t1;
    t1.show();
    //коструктор с параметрами 
    Staff t2("Felix", "Boss", 15000);
    t2.show();
    //конструктор копирования
    Staff t3 = t2;
    t3.set_FIO("Ivan");
    t3.set_status("Worker");
    t3.set_pay(5000);
    //конструктор копирования
    print_Staff(t3);
    //конструктор копирования
    t1 = make_Staff();
    t1.show();
}
