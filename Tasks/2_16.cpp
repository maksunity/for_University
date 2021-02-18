#include <iostream>
using namespace std;
int n;
int sum;
int main()
{
    sum=0;
    cout << "Введите кол-во чисел в последовательности";
    cout << endl;
    cout << endl;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        if ((i%2)==0)
        {
            sum = sum+i;
        }
        else 
        {
            sum = sum-i;
        }
    }   
    cout << "Сумма последовательности равна: ";
    cout << endl;
    cout << endl;
    cout << sum;
    return 0;
}