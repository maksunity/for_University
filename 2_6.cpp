#include <iostream> 
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=n; i>0;i--)
    {
        for (int j=0; j<n;j++)
        {
            if (j+i>=n)
            {
                cout << '*';
            }
            else
            {
                    cout << " ";
            }
            
        }
        cout << "\n";
    }
    return 0;
}