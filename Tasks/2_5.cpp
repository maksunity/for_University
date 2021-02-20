// Программа выводит прямоугольный треугольник с катетами равными значению n, и прямым углом снизу справа. Сначала вводится параматер n, отвечающий за длины катетов. 
// Сначала запускается цикл, отвечающий за достижение i значения n. Затем ставится пробел до тех пор, пока сумма i и j не достигнет значения n. 
// Как только оно достигается ставится символ "*", а курсор переходит на следующую строку. Отличие от прошлой программы в том, что если ставить символ "*", а не "* ", то
// Мы как раз-таки и будем получать разные виды треугольника.
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
                    cout << "*";
            }
            
        }
        cout << "\n";
    }
    return 0;
}