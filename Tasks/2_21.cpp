#include <iostream>
using namespace std;
int n,k;
int a[100];
bool flag=false;
int main()
{
    cout << "Введите числа: ";
    cout << endl;
    cout << endl;
    for (int i=1; 100; i++)
    {
        cin >> a[i];
        k++;
        if (a[i]==0)
        {
            break;
        }
    }
    for (int i=2; i<k; i++)
    {
        if(a[i-1]<=a[i])
        {
            flag=true;
        }
    }

    if (flag==true)
    {
    cout << "Последовательность упорядочена";
    }
    else
    {
    cout << "Последовательность не упорядочена";
    }
    
    return 0;
}