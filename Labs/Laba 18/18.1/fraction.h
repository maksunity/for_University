#include <iostream>
#include <string>
using namespace std;

class fraction
{
    double x_first;
    double x_second;
    double y_first;
    double y_second;

public:
    fraction();
    ~fraction();
    fraction(double, double);
    void Init(double, double);                 //метод для инициализации полей
    void Read(double, double, double, double); //метод для чтения значений полей
    void Show();                               //метод для вывода значений полей
    float Distance(double, double);            //вычисление степени

};
