#include <iostream>
#include <vector>

using namespace std;

int n[19] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9};

bool check (vector <int> k, int num)
{
    bool f = false;
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == num)
        {
            f = true;
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
                if (k[j] > k[j + h])
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

vector <int> enter(vector <int> k)
{
    cout << "Выберите вариант заполнения:" << endl;
    cout << "1 - автоматическое заполнение" << endl;
    cout << "2 - ручное заполнение" << endl;
    cout << "3 - по параметрам" << endl;
    char chose;
    cin >> chose;
    int r;
    switch (chose)
    {
    case '1':
        cout << "Введите количество элементов меньше 20: " << endl;
        cin >> r;

        while (r > 19)
        {
            cout << "Error: слишком много элементов " << endl;
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
        cout << "Введите количество элементов меньше 20: " << endl;
        cin >> r;

        while (r > 19)
        {
            cout << "Error: слишком много элементов " << endl;
            cin >> r;
        }

        cout << "Введите числа от -9 до 9" << endl;
        for (int i = 0; i < r; i++)
        {
            int s;
            cin >> s;
            while (check(k, s) || s < -9 || s > 9)
            {
                if (check(k, s))
                {
                    cout << "Error: такое число уже есть.. " << endl;
                    cin >> s;
                }
                if (s < -9 || s > 9)
                {
                    cout << "Error: выход за диапазон.." << endl;
                    cin >> s;
                }
            }
            k.push_back(s);
        }
        k = Sort(k);

        return k;
        break;

    case '3':
        cout << "Выберите операцию: " << endl;
        cout << "1 - ввод по четности" << endl;
        cout << "2 - ввод отрицательных или положительных" << endl;
        cout << "3 - ввод по кратности" << endl;

        char q;
        cin >> q;
        switch (q)
        {
        case '1':
            cout << "Введите 1 для ввода нечетных, 2 для четных " << endl;
            char ch;
            cin >> ch;
            while (ch != '1' && ch != '2')
            {

                cout << "Error: неверное число.." << endl;
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
            cout << "Введите + для заполнения положительными, - для отрицательных: " << endl;
            char z;
            cin >> z;
            while (z != '+' && z != '-')
            {
                cout << "Error: не корректный ввод.." << endl;
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
            cout << "Введите делитель от -9 до 9 (кроме 0): " << endl;
            int c;
            cin >> c;
            while (c < -9 || c > 9 || c == 0)
            {
                cout << "Error: неверный ввод.." << endl;
                cin >> c;
            }
            for (int i = 0; i < 19; i++)
            {
                if (n[i] % c == 0)
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


vector <int> sum(vector <int> a, vector <int> b)
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
    for (int i = 0; i < k.size(); i++)
    {
        cout << k[i] << " ";
    }
}


vector <vector <int>> oper(vector <int> a, vector <int> b, vector <int> c, vector <int> result)
{
    vector <vector <int>> t;
    char z;

    cout << "Введите множество для заполнения: " << endl;
    cout << "1 - для множества a" << endl;
    cout << "2 - для множества b" << endl;
    cout << "3 - для множества c" << endl;
    cout << "4 - результаты прошлых вычислений" << endl;
    cin >> z;
    char w;

    switch (z)
    {

    case '1':
        cout << "Введите второе множество:" << endl;
        cout << "1 - множество b" << endl;
        cout << "2 - множество c" << endl;
        cout << "3 - результаты прошлых вычислений" << endl;
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
                cout << "Error: это множество пустое.." << endl;
        }
        return t;
        break;

    case '2':
        cout << "Введите второе множество:" << endl;
        cout << "1 - множество a" << endl;
        cout << "2 - множество c" << endl;
        cout << "3 - результаты прошлых вычислений" << endl;
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
                cout << "Error: это множество пустое.." << endl;
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
                cout << "Error: это множество пустое.." << endl;
        }
        return t;
        break;

    case '4':
        if (!result.empty())
        {
            cout << "Введите второе множество:" << endl;
            cout << "1 - множество a" << endl;
            cout << "2 - множество b" << endl;
            cout << "3 - множество c" << endl;
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
                    cout << "Error: это множество пустое.." << endl;
            }
            return t;
        }
        else
        {
            cout << "Error: это множество пустое.." << endl;
        }
        break;
    }
}