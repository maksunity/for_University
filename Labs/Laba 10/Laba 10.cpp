#include <iostream>
using namespace std;

int main(){
string* a, *p;
int n;
cout << "Введите кол-во cтрок: ";
cin >> n;
a = new string[n]; 
for (int i = 1; i <= n; i++)
{
    a[i]=(char) ('a' + rand() %25);
}

cout << "Введите строку для удаления: ";
int s;
cin >> s;

for (int i = s; i <=n; i++)
{
    a[i]=a[i+1];
}
 
for (int i = 1; i <=n; i++)
{
    cout << a[i];
}
delete[] a;

return 0;
}

