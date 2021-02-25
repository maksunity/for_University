#include <iostream> //DONE!
using namespace std;

int main(){
int n;
cout << "Введите кол-во cтрок: ";
cin >> n;
int *a = new int [n];
for (int i = 0; i < n; i++)
{
    a[i] = rand() %10;
}

cout << "Массив до удаления строки: ";
cout << endl;

for (int i = 0; i < n; i++)
{
    cout << a[i] << endl;
}

cout << endl;

cout << "Введите строку для удаления: ";
int s;
cin >> s;
 int buf = 0;
for (int i = s-1; i <=n; i++)
{
    buf = a[i];
    a[i]= a[i+1];
    a[i+1] = buf;
}
 
for (int i =0; i <n-1; i++)
{
    cout << a[i] << endl;;
}
delete[] a;

return 0;
}

