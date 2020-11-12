#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i=1; i<n;i++)
    {
        for (int j=0; j<n+i-2;j++)
        {
            if (i+j>n)
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