#include <iostream>
using namespace std;
int n;
int sum=0;
int main()
{
    cout << "Введите число элементов последовательности: ";
    cout << endl;
    cout << endl;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        if ((i%3)==0)
        {
            sum=sum-i;
        }
        else
        {
            sum=sum+i;
        }
    }
    cout << "Сумма последовательности равна: ";
    cout << endl;
    cout << endl;
    cout << sum;
    return 0;
}