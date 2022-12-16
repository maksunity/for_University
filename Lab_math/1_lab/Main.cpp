#include "Header.h"
#include <iostream>

#include <Windows.h>

using namespace std;

int main()
{
    bool flag = 1;
    vector <int> a;
    vector <int> b;
    vector <int> c;
    vector <int> result;
    vector <vector <int>> o;
    while (flag)
    {
        char com;
        cout << "Выберите вариант действия:" << endl;
        cout << "1 - ввод множества" << endl;
        cout << "2 - вывод множеств" << endl;
        cout << "3 - очистка множеств" << endl;
        cout << "4 - завершение вычислений" << endl;
        cout << "5 - выбор операции над множествами" << endl;
        cin >> com;
        switch (com)
        {
        case '1':
            a = enter(a);
            b = enter(b);
            c = enter(c);
            break;

        case '2':
            if (!a.empty() && !b.empty() && !c.empty() && !c.empty())
            {
                cout << "a: ";
                print(a);
                cout << endl << "b: ";
                print(b);
                cout << endl << "c: ";
                print(c);
                cout << endl << "Result: ";
                print(result);
                cout << endl;
            }
            break;

        case '3':
            a.clear();
            b.clear();
            c.clear();
            result.clear();
            break;

        case '4':
            flag = 0;
            cout << "Have a nice day!";
            Sleep(2000);
            exit(0);

        case '5':
            char q;
            cout << "Выберите операцию: " << endl;
            cout << "1 - Пересечение" << endl;
            cout << "2- Объединение" << endl;
            cout << "3 - Разность" << endl;
            cout << "4 - Симметрическая разность" << endl;
            cout << "5 - Дополнение" << endl;
            cin >> q;

            switch (q)
            {
            case '1':
                o = oper(a, b, c, result);
                result = inter(o[0], o[1]);
                print(o[0]);
                cout << endl;
                print(o[1]);
                cout << endl;
                print(result);
                cout << endl;
                break;

            case '2':
                o = oper(a, b, c, result);
                result = unific(o[0], o[1]);
                print(o[0]);
                cout << endl;
                print(o[1]);
                cout << endl;
                print(result);
                cout << endl;
                break;

            case '3':
                o = oper(a, b, c, result);
                result = without(o[0], o[1]);
                print(o[0]);
                cout << endl;
                print(o[1]);
                cout << endl;
                print(result);
                cout << endl;
                break;

            case '4':
                o = oper(a, b, c, result);
                result = sum(o[0], o[1]);
                print(o[0]);
                cout << endl;
                print(o[1]);
                cout << endl;
                print(result);
                cout << endl;
                break;

            case '5':
                char w;
                cout << "Введите множество для дополнения: " << endl;
                cout << "1 - множество a " << endl;
                cout << "2 - множество b" << endl;
                cout << "3- множество c" << endl;
                cout << "4 - множество с результатом" << endl;
                cin >> w;
                if (w == '1')
                {
                    result = no(a);
                }
                else if (w == '2')
                {
                    result = no(b);
                }
                else if (w == '3')
                {
                    result = no(c);
                }
                else if (w == '4')
                {
                    if (!result.empty())
                    {
                        result = no(result);
                    }
                    else
                        cout << "Error: множество пустое, выберите другое" << endl;
                }
                break;
            }
            break;
        }
    }
}