// Программа выводит равнобедренный треугольник с n звездочками в основании.
// Сначала вводится значение переменной n. Затем запускается цикл пока i не достигнет n, сразу после этого запускается второй цикл. И если сумма не равна i+j n, то ставится пробел.
// Когда они достигнут n, то ставится "* ", а курсор ставится на следущую строку. И так до тех пор, пока кол-во сумма i+j сразу же не будет равна n, в том случае получим строку, равную n звездочек.
#include <iostream> 
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i=1; i<=n;i++)
    {
        for (int j=1; j<=n;j++)
        {
            if (i+j<=n)
            {
                cout << ' ';
            }
            else
            {
                    cout << "* ";
            }
            
        }
        cout << "\n";
    }
    return 0;
}