#include <iostream>
using namespace std;
int main()
{
int n,m,k;
cout << "Введите кол-во элементов: ";
cout << endl;
cout << endl;
cin >> n;
int a[1000];
cout << "Рандомный массив: ";
cout << endl;
cout << endl;
for (int i=1; i<=n; i++)
{
    a[i]=rand()%100-50; //Рандомятся числа для массива
}
 for (int i=1; i<=n; i++)
 {
     cout << a[i] << " "; //Выводится изначальный массив
 }
 cout <<endl;
 cout << endl;
 cout << "Введите поочередно числа K, а затем M: ";
        cin >> k >> m; //задаются значения для k и m
        cout << "Массив в котором удалены с K места M элементов: ";
        cout << endl;
     for (int i=k; i<=n-m; i++ ) // запускается цикл с K по М элемента
     {
         a[i]=a[i+m];
     }
     for (int i=1; i<=n-m; i++) 
 {
     cout << a[i] << " "; // Выводится новый массив
 }
 cout << endl;
 cout << endl;
 cout << "Введите число на которое хотите увеличить массив: ";
cin >> k; // считывается кол-во новых рандомных элементов в массиве
    cout << "Увелечение массива на K элементов рандомными числами: ";
    cout << endl;
    cout << endl;
    for (int i=n-m+1; i<=n-m+k; i++) // цикл от послежнего элемента до нового
    {
    a[i]=rand()%100-50; // присвоение рандомного значения
    } 
 for (int i=1; i<=n-m+k;i++) // вывод массива
 {
     cout << a[i] << " ";
 }
 cout << endl; //сброс строки вниз
 cout << endl;
 cout << "Перевернутый массив: ";
 cout << endl;
n=n-m+k; //присвоение переменной значения для упрощения в использовании
int buf;
int j=0;
for (int i=1; i<=(n/2); i++) //цикл от первого до кратного, тк если кол-во элементов будет четным, то поменяются все элементы между собой, а если будет нечетным, то поменяются все кроме "центрального"
{
    buf=a[i]; //присвоение "буферу" значения элемента массива
    a[i]=a[n-j];
    a[n-j]=buf;
    j++;
}
 for (int i=1; i<=n; i++) //вывод массива
 {
     cout << a[i] << " ";
 }
cout << endl;
cout << endl;
cout << "Первый отрицательный элемент: ";
cout << endl;
cout << endl;
bool flag=false;
for (int i=1; i<=n; i++)
{
    if (a[i]<0)
    {
        flag=true;
        cout << a[i] << endl;
        break;
    }    
}
cout << endl;
if (flag==false)
{
    cout << "Такого элемента нет";
}
cout << endl;
cout << "Сортировка методом обмена: ";
cout << endl;

for (int i=n; i>=2; i--)
{
    for (int j=i-1; j>=1;j--)
    {
        if (a[i]<a[j])
        {
            buf=a[j];
            a[j]=a[i];
            a[i]=buf;
        }
    }
}

for (int i=1; i<=n; i++)
{
    cout << a[i] << " ";
}
return 0;
}
