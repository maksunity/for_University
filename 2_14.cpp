#include <iostream>
#include <string> 
using namespace std;
int sum;
string n;
int main()
{
    sum=0;
    cout << "Введите число: ";
    cout <<endl;
    cin >> n;
    cout <<endl;
    cout <<endl;
    for (int i=n.length(); i>=0; i--)
    {
        int n;
        sum=sum+(n%10);
        n=n/10;
    }
    cout << "Сумма числа: ";
    cout << sum;
    return 0;
}