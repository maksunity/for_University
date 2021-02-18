#include <iostream> 
#include <cmath>
using namespace std;
float n;
float number;
float maxi = INT_MIN;
int main()
{

    cout << "Введите кол-во элементов: ";
    cout << endl;
    cout << endl;
    cin >> n;
    cout << endl;
    for (int i=1; i<=n; i++)
    {
        if ((sin(n+i/n)) >= maxi)
        {
            number = i;
            maxi = sin(n+i/n);
        }
    }
    cout << number << " " << maxi;
    return 0;
}