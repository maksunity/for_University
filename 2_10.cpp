#include <iostream>
using namespace std;
int n;
int maximum;
int a;
int main()
{
maximum=0;
cout << "Введите кол-во элементов последовательности: ";
cout << endl;
cout << endl;
cin >> n;
for (int i=1; i<=n; i++)
{
    cin >> a;
    if (a>=maximum)
    {
        maximum=a;
    }
}
cout << "Максимальный элемент массива: ";
cout << endl;
cout << maximum;
return 0;
}

