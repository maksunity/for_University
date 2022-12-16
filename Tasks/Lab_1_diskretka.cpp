#include <iostream>
#include <vector>
using namespace std;
int n[19] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9};
bool check(vector <int> k, int num)
{
    bool f = 0;
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == num)
        {
            f = 1;
        }
    }
    return f;
}
vector <int> Sort(vector <int> k)
{
    int n = k.size();
    int h = n / 2;
    while (h > 0)
    {
        for (int i = 0; i < n - h; i++)
        {
            int j = i;
            while (j >= 0)
            {
                if (k[j]> k[j + h])
                {
                    int d = k[j];
                    k[j] = k[j + h];
                    k[j + h] = d;
                    j -= h;
                }
                else
                    j = -1;
            }
        }
        h /= 2;
    }
    return k;
}
vector <int> vvod(vector <int> k)
{
    cout << "Введите 1 - автоматическая генерация, 2 - ввод вручную, 3 - по четности, знаку или кратности " << endl;
    char d;
    cin >> d;
    int r;
    switch (d)
    {
        case '1':
            cout << "Введите размер множества, меньший 20 "<< endl;
            cin >> r;
            while (r > 19)
            {
                cout << "Размер множества должен быть меньше 20, введите новый " << endl;
                cin >> r;
            }
            for (int i = 0; i < r; i++)
            {
                int s = n[rand() % 20];
                while (check(k, s))
                {
                    s = n[rand() % 20];
                }
                k.push_back(s);
            }
            k = Sort(k);
            return k;
        break;
        case '2':
            cout << "Введите размер множества, меньший 20 " << endl;
            cin >> r;
            while (r > 19)
            {
                cout << "Размер множества должен быть меньше 20, введите новый " << endl;
                cin >> r;
            }
            cout << "Введите числа от -9 до 9 " << endl;
            for (int i = 0; i < r; i++)
            {
                int s;
                cin >> s;
                while (check(k, s) || s < -9 || s > 9)
                {   
                    if (check(k, s))
                    {
                        cout << "Такое число уже есть, введите другое " << endl;
                        cin >> s;
                    }
                    if (s < -9 || s > 9)
                    {
                        cout << "Число не удовлетворяет условие, введите в диапазоне от -9 до 9 " << endl;
                        cin >> s;
                    }
                }
                k.push_back(s);
            }
            k = Sort(k);
            return k;
        break;
        case '3':
            cout << "Введите операцию 1 - ввод четных или нечетных, 2 - ввод отрицательных или положительных, 3 - ввод по кратности " << endl;
            char q;
            cin >> q;
            switch (q)
            {
            case '1':
                cout << "Введите 1 - не четное, 2 - четные " << endl;
                char ch;
                cin >> ch;
                while (ch != '1' && ch != '2')
                {

                    cout << "Не корректный ввод, введите 1 или 2" << endl;
                    cin >> ch;
                }
                if (ch == '2')
                {
                    for (int i = 1; i < 19; i += 2)
                    {
                        k.push_back(n[i]);
                    }
                }
                else
                {
                    for (int i = 0; i < 19; i += 2)
                    {
                        k.push_back(n[i]);
                    }
                }
                return k;
                break;
            case '2':
                cout << "Введите + - положительные, - - отрицательные " << endl;
                char z;
                cin >> z;
                while (z != '-' && z != '+')
                {
                        cout << "Не корректный ввод, введите + или -" << endl;
                        cin >> z;
                }
                if (z == '-')
                {
                    for (int i = 0; i < 9; i++)
                    {
                        k.push_back(n[i]);
                    }
                }
                else if (z == '+')
                {
                    for (int i = 9; i < 19; i++)
                    {
                        k.push_back(n[i]);
                    }
                }
                return k;
                break;
            case '3':
                cout << "Введите делитель от -9 до 9, исключая 0" << endl;
                int c;
                cin >> c;
                while (c < -9 || c > 9 || c == 0)
                {
                    cout << "Не корректный ввод, введите значение от -9 до 9, исключая 0" << endl;
                    cin >> c;
                }
                for (int i = 0; i < 19; i++)
                {
                    if(n[i] % c == 0)
                    k.push_back(n[i]);
                }
                return k;
                break;
            }
        break;
    }
}
vector <int> inter(vector <int> a, vector <int> b)
{
    vector <int> c;
    for (int i = 0; i < a.size(); i++)
    {
        if (check(b, a[i]))
        {
            c.push_back(a[i]);
        }
    }
    return c;
}
vector <int> unific(vector <int> a, vector <int> b)
{
    vector <int> c;
    for (int i = 0; i < a.size(); i++)
    {
        c.push_back(a[i]);
    }
    for (int j = 0; j < b.size(); j++)
    {
        if (!check(c, b[j]))
        {
           c.push_back(b[j]);
        }
    }
    c = Sort(c);
    return c;
}
vector <int> without(vector <int> a, vector <int> b)
{
    vector <int> c;
    for (int i = 0; i < a.size(); i++)
    {
        if (!check(b, a[i]))
        {
            c.push_back(a[i]);
        }
    }
    return c;
}
vector <int> symmetry(vector <int> a, vector <int> b)
{
    vector <int> c;
    for (int i = 0; i < a.size(); i++)
    {
        if (!check(b, a[i]))
        {
            c.push_back(a[i]);
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (!check(a, b[i]))
        {
            c.push_back(b[i]);
        }
    }
    return c;
}
vector <int> no(vector <int> a)
{
    vector <int> c;
    for (int i = 0; i < 19; i++)
    {
        if (!check(a, n[i]))
        {
            c.push_back(n[i]);
        }
    }
    return c;
}
void print(vector <int> k)
{
    for (int i = 0;i<k.size();i++)
    {
        cout << k[i] << " ";
    }
}
vector <vector <int>> oper(vector <int> a, vector <int> b, vector <int> c, vector <int> result)
{
    vector <vector <int>> t;
    char z;
    cout << "Введите первое множество: " << endl << "1 - множество а" << endl << "2 - множество b" << endl <<"3 - множество с "<< endl << "4 - множество результата прошлых вычислений" << endl;
    cin >> z;
    char w;
    switch (z)
    {
    case '1':
        cout << "Введите второе множество:" << endl << "1 - множество b" << endl << "2 - множество c" << endl << "3 - множество результата прошлых вычислений" << endl;
        cin >> w;
        if (w == '1')
        {
            t.push_back(a);
            t.push_back(b);
        }
        else if (w == '2')
        {
            t.push_back(a);
            t.push_back(c);
        }
        else if (w == '3')
        {
            if (!result.empty())
            {
                t.push_back(a);
                t.push_back(result);
            }
            else
                cout << "Это множество пустое, выполните другое действия над существующими множествами" << endl;
        }
        return t;
        break;
    case '2':
        cout << "Введите второе множество:" << endl << "1 - множество a" << endl << "2 - множество c" << endl << "3 - множество результата прошлых вычислений" << endl;
        cin >> w;
        if (w == '1')
        {
            t.push_back(b);
            t.push_back(a);
        }
        else if (w == '2')
        {
            t.push_back(b);
            t.push_back(c);
        }
        else if (w == '3')
        {
            if (!result.empty())
            {
                t.push_back(b);
                t.push_back(result);
            }
            else
                cout << "Это множество пустое, выполните другое действия над существующими множествами" << endl;
        }
        return t;
        break;
    case '3':
        cin >> w;
        if (w == '1')
        {
            t.push_back(c);
            t.push_back(a);
        }
        else if (w == '2')
        {
            t.push_back(c);
            t.push_back(b);
        }
        else if (w == '3')
        {
            if (!result.empty())
            {
                t.push_back(c);
                t.push_back(result);
            }
            else
                cout << "Это множество пустое, выполните другое действия над существующими множествами" << endl;
        }
        return t;
        break;
    case '4':
        if (!result.empty())
        {
            cout << "Введите второе множество:" << endl << "1 - множество a" << endl << "2 - множество b" << endl << "3 - множество c" << endl;
            cin >> w;
            if (w == '1')
            {
                t.push_back(result);
                t.push_back(a);
            }
            else if (w == '2')
            {
                t.push_back(result);
                t.push_back(b);
            }
            else if (w == '3')
            {
                if (!result.empty())
                {
                    t.push_back(result);
                    t.push_back(c);
                }
                else
                    cout << "Это множество пустое, выполните другое действия над существующими множествами" << endl;
            }
            return t;
        }
        else
        {
            cout << "Множесвто пустое, предыдущих вычмслений нет " << endl;
        }
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    bool flag = 1;
    vector <int> a;    
    vector <int> b;
    vector <int> c;
    vector <int> result;
    vector <vector <int>> o;
    while (flag)
    {
        char com;
        cout << "Введите:" << endl <<"1 - ввод множеств" << endl << "2 - вывод всех множеств" << endl << "3 - очистка всех множеств" << endl << "4 - конец вычислений" << endl << "5 - операции над множествами " << endl;
        cin >> com;
        switch (com)
        {
        case '1':
            a = vvod(a);
            b = vvod(b);
            c = vvod(c);
            break;
        case '2':
            if (!a.empty() && !b.empty()&& !c.empty() && !c.empty())
            {
                cout << "a: ";
                print(a);
                cout << endl << "b: ";
                print(b);
                cout << endl << "c: ";
                print(c);
                cout << endl << "result: ";
                print(result);
                cout << endl;
            }
            break;
        case 3:
            a.clear();
            b.clear();
            c.clear();
            result.clear();
            break;
        case '4':
            flag = 0;
            break;
        case '5':
            char q;
            cout << "Введите операцию: " << endl <<  "1 - Пересечение" << endl << "2- объединение" << endl <<"3 - разность" << endl <<"4 - симметричная разность" << endl << "5 - дополнение" << endl;
            cin >> q;
                switch (q)
                {
                case '1':
                    o = oper(a,b,c, result);
                    result = inter(o[0],o[1]);
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
                    result = symmetry(o[0], o[1]);
                    print(o[0]);
                    cout << endl;
                    print(o[1]);
                    cout << endl;
                    print(result);
                    cout << endl;
                    break;
                case '5':
                    char w;
                    cout << "Введите множество для дополнения: " << endl << "1 - множество а " << endl <<  "2 - множество b" << endl << "3- множество c"  << endl << "4 - множество результат " << endl;
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
                    else if(w == '4')
                    {
                        if (!result.empty())
                        {
                            result = no(result);
                        }
                        else
                            cout << "Это множество пустое, выполните другое действия над существующими множествами" << endl;
                    }
                    break;
                }
            break;
        }
    }
}