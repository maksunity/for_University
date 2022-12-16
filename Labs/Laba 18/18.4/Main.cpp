#include <iostream>
#include "header.h"
using namespace std;
void main()
{
    Triada a;
    cin >> a;
    cout << a;
    Triada b(10, 4, 115);
    cout << b;
    a = b;
    cout << a;
}
