#include <iostream>
using namespace std;
int a,b;
int main()
{
    cin >> a;
    cin >> b;
    if (a==0)
    {
        cout << 0;
    }
    else
    {
        if (b==0)
        {
            cout << "Так не делается, дорогой! Ответ никто не знает(";
        }
    }
    if (a!=0 && b!=0)
    {
       cout << a/b;
    }
    return 0;
}