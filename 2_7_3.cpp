#include <iostream> // ГОТОА НЕ ДО КОНЦА
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n;i++)
    {
        cout << "* ";
    }

    for (int i=1; i<n; i++)
    {
        for (int j=1; j<n; j++)
        { 
           if (i<=j)
           {
               cout << " ";
           }
           else
           {
               cout << "* "; 
               break;
           }    
        }
        cout << "\n";
    }

    for (int i=1; i<=n; i++)
    {
        cout << "* ";
    }
    return 0;
}

