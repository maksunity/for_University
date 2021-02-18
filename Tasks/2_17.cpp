#include <iostream>
#include <cmath>
using namespace std;
float sum,x,f;
int n,i;
int main()
{
    sum=1;
    f=1;
    cout << "Введите длину последовательности: ";
    cout << endl;
    cout << endl;
    cin >> n;
    cout << endl;
    cout << endl;
    cout << "Введите значения переменной X: ";
    cout << endl; 
    cin >> x;
    if (n==1)
    {
        cout << sum;
    }
    if (n==0)
    {
        cout << 0;
        goto skip;
    }
    if ((n!=0) && (n!=1))
    {
        for (int i=2; i<=n; i++)
        {
        sum = sum + pow(x,i-1)/f;
        f = f*i;
        }
    }
    cout << "Сумма последовательности равна: ";
    cout << endl;
    cout << sum; 
    skip:
    return 0;
}