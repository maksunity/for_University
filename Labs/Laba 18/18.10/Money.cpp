#include "Money.h"

Money::Money()
{
    rub = 0;
    kop = 0;
}

Money::Money(long r, int k)
{
    rub = r;
    kop = k;
}

Money::Money(const Money &m)
{
    rub = m.rub;
    kop = m.kop;
}

Money Money::operator=(const Money &m)
{
    if (&m == this)
        return *this;
    rub = m.rub;
    kop = m.kop;
    return *this;
}

Money::~Money() {}

ostream &operator<<(ostream &out, const Money &m)
{
    out << "RUB: " << m.rub << endl;
    out << "KOP: " << m.kop << endl;
    return out;
}

istream &operator>>(istream &in, Money &m)
{
    cout << "Enter RUB: " << endl;
    ;
    in >> m.rub;

    cout << "Enter KOP: " << endl;
    in >> m.kop;
    return in;
}

fstream &operator>>(fstream &fin, Money &m)
{
    fin >> m.rub;
    fin >> m.kop;
    return fin;
}
fstream &operator<<(fstream &fout, const Money &m)
{
    fout << m.rub << endl;
    fout << m.kop << endl;
    return fout;
}
