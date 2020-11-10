#include <iostream>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    if (a > b && a > c)
    {
        cout << a;
    }
    if (b>a && b>c)
    {
        cout << b;
    }
    if (c > a && c > b)
    {
        cout << c;

    }
    return 0;
}