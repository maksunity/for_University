#include <iostream>
#include <string> 
using namespace std;
int z,n;
bool flag=false;
int main()
{
    cout << "Введите число: ";
    cout << endl;
    cout << endl;
    cin >> n;
    cout << endl;
    cout << endl;
    cout << "Введите цифру для проверки его в N: ";
    cout << endl;
    cout << endl;
    cin >> z;
    while (n % 10 >0)
    {
        if ((n%10)==z)
        {
            flag=true;
            break;
        }
        else
        {
            n=n/10;
        }
        
    }
    if (flag == true)
    {
        cout << "Цифра Z входит в число N";
    }
    else
    {
        cout << "Цифра Z не входит в число N";
    }
    return 0;
}