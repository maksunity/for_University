#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;
//реализация метода для инициализации полей структуры 
void fraction::Init(double F, double S)
{
first=F; 
second=S;
}
//реализация метода для чтения значений полей структуры 
void fraction::Read()
{
cout<<"\nfirst?"; 
cin>>first; 
cout<<"\nsecond?";
cin>>second;
}
//реализация метода для вывода значений полей структуры 
void fraction::Show()
{
cout<<"\nfirst="<<first;
cout<<"\nsecond="<<second;
cout<<"\n";
}
//метод для возведения в степень 
double fraction::Power()
{
return pow (first, second);
}
