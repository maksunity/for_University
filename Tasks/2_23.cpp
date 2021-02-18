#include <iostream> 
#include <cmath>
using namespace std;
float maxi = INT_MIN;
float n;
int k;
int main()
{
    k=0;
    cout << "Введите кол-во элементов: ";
    cout << endl;
    cout << endl;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        if (sin(n+i/n)>maxi)
        {
            maxi = sin(n+i/n);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (sin(n+i/n)==maxi)
        {
            k++;
        }
    }
    cout << "Кол-во элементов, равных максимальному: " << k;
    return 0;
}