#include<iostream>

using namespace std;

void Shell(int n, int *a)
{
    int k = n/2;
    int j;
    while (k > 0)
    {
        for (int i = 0; i < n-k; i++)
        {
            j=i;
            while (j >= 0)
            {
                if (a[j] > a[j+k])
                {
                    int buf = a[j];
                    a[j] = a[j+k];
                    a[j+k] = buf;
                }
                else
                j = -1;
            }
        }
        k = k/2;
    }
}


int main()
{
    int n;
    cout << "Kolvo Element: ";
    cin >> n;
    int a[128];

    cout << "Elements: ";
    for (int i = 0; i<n; i++)
    {
        cin >> a[i];
        cout << endl;
    }   
    cout << "Array before sort: ";

    for (int i = 0; i<n; i++)
    {
        cout << a[i] << " ";
    }   

    cout << endl << "Array after sort: ";

    Shell(n,a);

      for (int i = 0; i<n; i++)
    {
        cout << a[i] << " ";
    }  

    return 0;
}