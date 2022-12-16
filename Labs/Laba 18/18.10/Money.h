#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Money
{
public:
    Money();
    Money(long, int);
    Money(const Money &);
    Money operator=(const Money &);
    friend ostream &operator<<(ostream &out, const Money &m);
    friend istream &operator>>(istream &in, Money &m);
    friend fstream &operator>>(fstream &fin, Money &m);
    friend fstream &operator<<(fstream &fout, const Money &m);

public:
    ~Money();

private:
    long rub;
    int kop;
};