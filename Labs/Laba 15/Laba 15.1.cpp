#include <iostream> // DONEEE!!!
using namespace std;
int n;
struct Bus{ 
    int m;
    int d;
};

void Shell(Bus *a, int n)
{
    int k = n / 2;
    int j;
    while (k > 0)
    {
        for (int i = 0; i < n - k  ; i++)
        {
            j = i;
            while (j >= 0 )
            {
                if (a[j].d > a[j + k].d)
                {
                    int buf1 = a[j].d;
                    a[j].d = a[j + k].d;
                    a[j + k].d = buf1;
                    int buf2 = a[j].m;
                    a[j].m = a[j + k].m;
                    a[j + k].m = buf2;
                }
                else
                    j = -1;
            }
        }
        k = k / 2;
    }
}

int main()
{
    cout << "Enter num of bus: " << endl;
    cin >> n;
    Bus *p = new Bus[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter bus number: " << endl;
        cin >> p[i].m;
        cout << endl;
        cout << "Enter lenght of route: " << endl;
        cin >> p[i].d;
    }
    Shell(p, n);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Bus " << i << "Number"
             << " " << p[i].m << " ";
        cout << "Lenght route"
             << " " << p[i].d << endl;
    }
    return 0;
}
