#include <iostream> 
#include <cmath>
using namespace std;
int n;
float z;
bool flag=false;
int sum=0;
int main()
{
    cout << "Введите кол-во элементов последовательности: ";
    cout << endl;
    cout << endl;
    cin >> n;
    cout << endl;
    cout << endl;
    cout << "Введите число для сравнения: ";
    cout << endl;
    cin >> z;
    for (int i=1; i<n; i++)
    {
        if (sin(n+i/n)==z)
        {
            flag=true;
            break;
        }
    }
    if (flag==true)
    {
        cout << "Такой элемент есть";
    }   
    else
    {
        cout << "Такого элемента нет";
    }
    return 0;
}