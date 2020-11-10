#include <iostream>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    if (a>b) & & (a>c)
    {
        cout<<a;
    }
    if (a<b) & & (b>c)
{
    cout<<b;
}
if (c>b) & & (c>a)
{
    cout<<c;
}
return 0
}