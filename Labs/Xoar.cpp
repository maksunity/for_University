#include <iostream>

using namespace std;

void Hoar(int *a, int Left, int Right)
{
    int buf;
    int i = Left;
    int j = Right;
    int mid = (Left + Right) / 2;

    while (i <= j)
    {
        while (a[i] < a[mid])
        {
            i++;
        }
        while (a[j] > a[mid])
        {
            j--;
        }
        if (i <= j)
        {
            buf = a[i];
            a[i] = a[j];
            a[j] = buf;
            i++;
            j--;
        }
    }
    if (i < Right)
    {
        Hoar(a, i, Right);
    }
    if (Left < j)
    {
        Hoar(a, Left, j);
    }
}

int main()
{
    int n;
    cout << "Kolvo Element: ";
    cin >> n;
    int a[128];

    cout << "Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << endl;
    }
    cout << "Array before sort: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl << "Array after sort: ";

    Hoar(a, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}