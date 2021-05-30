#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    btree t;
    int n;
    cout << "Enter N: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        t.insert(a);
    }
    t.print();
    t.count();
    cout << c/n;
}