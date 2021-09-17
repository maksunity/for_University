#include <iostream>

using namespace std;

const int N = 100;

void sort(int arr[N], int n)
{
    int x;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            x = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = x;
            i = 0;
        }
    }
}

int main()
{
    int mas1[N];
    int mas2[N];
    int mas3[N*2];
    int n1 = 0, n2 = 0, j = 0;
    int a, i;
    cout << "Kolvo elemnts in first array: ";
    cin >> n1;

    for (i = 0; i < n1; i++)
    {
        cout << "Enter " << i + 1 << " element arr " << endl;
        cin >> mas1[i];
    }

    for (i = 0; i < n1; i++)
        cout << mas1[i] << " ";
    cout << endl;

    cout << "Kolvo elemnts in second array:";
    cin >> n2;

    for (i = 0; i < n2; i++)
    {
        cout << "Enter " << i + 1 << " element arr  " << endl;
        cin >> mas2[i];
    }

    for (i = 0; i < n2; i++)
        cout << mas2[i] << " ";
    cout << endl;

    for (i = 0; i < n1; i++)
    {
        mas3[j] = mas1[i];
        j++;
    }

    for (int i = 0; i < n2; i++)
    {
        mas3[j] = mas2[i];
        j++;
    }

    sort(mas3, n1 + n2);

    cout << "Sorted array: ";
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << mas3[i];
        cout << " ";
    }

    return 0;
}