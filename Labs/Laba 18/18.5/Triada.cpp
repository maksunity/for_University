#include "Triada.h"

Car::Car(void)
{
    mark = 0;
    cyl = 0;
    power = 0;
}
Car::~Car(void)
{
}
Car::Car(int M, int C, int P)
{
    mark = M;
    cyl = C;
    power = P;
}
Car::Car(const Car &car)
{
    mark = car.mark;
    cyl = car.cyl;
    power = car.power;
}
void Car::Set_cyl(int C)
{
    cyl = C;
}
void Car::Set_mark(int M)
{
    mark = M;
}
void Car::Set_power(int P)
{
    power = P;
}
Car &Car::operator=(const Car &c)
{
    if (&c == this)
        return *this;
    mark = c.mark;
    power = c.power;
    cyl = c.cyl;
    return *this;
}
istream &operator>>(istream &in, Car &c)
{
    cout << "\nMark:";
    in >> c.mark;
    cout << "\nPower:";
    in >> c.power;
    cout << "\nCyl:";
    in >> c.cyl;
    return in;
}
ostream &operator<<(ostream &out, const Car &c)
{
    out << "\nMARK : " << c.mark;
    out << "\nCYL : " << c.cyl;
    out << "\nPOWER : " << c.power;
    out << "\n";
    return out;
}
void Car::Show()
{
    cout << "\nMARK : " << mark;
    cout << "\nCYL : " << cyl;
    cout << "\nPOWER : " << power;
    cout << "\n";
}
