#include <iostream>
using namespace std;
int n,buf;
int main()
{
    buf=0;
    cout << "Введите число N: ";
    cout << endl;
    cout << endl;
    cin >> n;
    while ((n%10)>0)
    {
        buf = buf + (n%10);
        buf = buf*10;
        n=n/10;      
    }
    cout << "Число N в обратно поярдке: ";
    cout << endl; 
    cout << buf/10;
    return 0;
}