#include <iostream>
using namespace std;
int n;
int chislo;
int a;
bool flag;
int main()
{
    cout << "Введите кол-во элементов";
    cout << endl;
    cout << endl;
    cin >> n;
    cout << "Вводите элементы последовательности: ";
    cout << endl;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        if (a==0)
        {
            flag=false;
        }
        if (a>0)
        {
            cout << "Последовательность положительная";
            flag=true;
            break;
        }
        if (a<0)
        {
            cout << "Последовательность отрицательная";
            flag=true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Последовательность нулевая";
    }
    return 0;
}