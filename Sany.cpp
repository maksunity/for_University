#include <iostream>
using namespace std;
int a[100];
int n,k;
int main()
{
    cout << "Введите кол-во элементов масисва";
    cout << endl;
    cin >>n;
    for (int i=0; i<=n;i++)
    {
        a[i]=rand()%100-50;
    }
    cout << "На сколько сдвигаем?";
    cin >> k;
    for (int i=n-k; i<=n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            a[j]=a[i];
        }
    }
    for (int i=n-k; i>=0; i--)
    {
        a[i]=a[i+k];
    }
    for (int i=0; i<=n-k-1; i++)
    {
        for (int j=0; j<=i; j++)
        {
            a[i]=a[j];
        }
    }
    for (int i=0; i<=n; i++)
    {
        cout << a[i];
    }
    return 0;
}