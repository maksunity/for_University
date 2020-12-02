#include <iostream>
using namespace std;
int n;
int maxi= INT_MIN;
int mini= INT_MAX;
int a;
int main()
{
    cout << "Введите кол-во элементов";
    cout << endl;
    cout << endl;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        {
            if (a>maxi)
            {
                maxi=a;
            }
            if (a<mini)
            {
                mini=a;
            }
        }
    }
    cout << maxi+mini;
    return 0;
}