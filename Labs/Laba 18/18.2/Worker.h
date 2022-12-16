#include <iostream>
#include <string>
using namespace std;
class Staff
{
    string FIO;
    string status;
    double pay;

public:
    Staff();                       //конструктор без параметров
    Staff(string, string, double);    //конструктор с параметрами
    Staff(const Staff &);          //конструктор копирования
    ~Staff();                      //деструктор
    string get_FIO();     //селектор
    void set_FIO(string); //модификатор
    string get_status();         //селектор
    void set_status(string);     //модификатор
    double get_pay();         //селектор
    void set_pay(double);     //модификатор
    void show();                   //просмотр атрибутов
};
