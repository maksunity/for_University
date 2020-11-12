#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n-1;i++)
    {
        for (int j=1; j<n+i-1;j++)
        {
            if (i+j>=n)
            {
                cout << '*';
            }
            else
            {
                    cout << ' ';
            }
            
        }
        cout << "\n";
    }
    return 0;
}