#include <iostream>
using namespace std;
class Time
{
public:
    Time operator+(Time k);
    Time(void);
    Time(int, int);
    Time(const Time &);
    Time &operator=(const Time &);
    //перегруженные операции ввода-вывода
    friend ostream &operator<<(ostream &out, const Time &);
    friend istream &operator>>(istream &in, Time &);

public:
    virtual ~Time(void){};

private:
    int min, sec;
};
