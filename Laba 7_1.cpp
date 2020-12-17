#include <iostream>
using namespace std;
int a[20];
int f(int n)
    {
       if (n%2!=0)
       {
           return n;
       }
       else 
       {
           return n%10;
       }
    }