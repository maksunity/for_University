// Программа рисует квадрат со строной равной n. 
// После этого запускатеся цикл, который работает n раз и каждый раз выводит символ "* ", а по достижению цикла j значения n, курсор скидывается на строку ниже.
// Цикл работает до тех пор, пока i не станет равным n.
#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}