// Программа выполняет деление одного числа на другое. Если первое число "0" вывести "0". Если второе число "0", то вывести "Так не делается дорогой...". 
//Если оба элемента не нулевые, то вывести результат деления 1-го числа на 2-ое. Программа поочередно выполняет все эти действия.
#include <iostream>
using namespace std;
int a,b;
int main()
{
    cin >> a; //Ввод числа
    cin >> b; //Ввод числа
    if (a==0)
    {
        cout << 0;
    }
    else
    {
        if (b==0)
        {
            cout << "Так не делается, дорогой! Ответ никто не знает(";
        }
    }
    if (a!=0 && b!=0)
    {
       cout << a/b; //Вывод результата.
    }
    return 0;
}