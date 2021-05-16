#include <iostream> //DONE!
#include<list>

using namespace std; 

struct carlist{
    string name;
    int serialnum;
    int regnum;
    int year;
};


int main()
{
    int a = 10;
    carlist car[a];
        car[1].name = "Renault";
        car[1].serialnum= 001;
        car[1].regnum= 999;
        car[1].year= 2019;

        car[2].name = "VAZ";
        car[2].serialnum= 002;
        car[2].regnum= 998;
        car[2].year= 1990;

        car[3].name = "Mazda";
        car[3].serialnum= 003;
        car[3].regnum= 997;
        car[3].year= 2020;

        car[4].name = "Peugeot";
        car[4].serialnum= 004;
        car[4].regnum= 996;
        car[4].year= 2004;

        car[5].name = "Nissan";
        car[5].serialnum= 005;
        car[5].regnum= 995;
        car[5].year= 2018;

        car[6].name = "Audi";
        car[6].serialnum= 006;
        car[6].regnum= 994;
        car[6].year= 2017;

        car[7].name = "Pontiac";
        car[7].serialnum= 007;
        car[7].regnum= 993;
        car[7].year= 2002;
    
    int k;
    cout << "Enter kolvo car for search: ";
    cin >>k;
    for (int i = 1; i <= k; i++){
        cout << i << "." << endl;
        cout << car[i].name << endl;
        cout << car[i].serialnum << endl;
        cout << car[i].regnum << endl;
        cout << car[i].year << endl;
        cout << endl;
    }
     
     cout << endl;

     cout << "Enter kolvo car for del: ";
     int del;
     int vivod; vivod=0;
     cin >> del;
     for (int i=1; i <= del; i++)
     {
         for (int j= 1; j < k; j++)
         {
            car[j].name =  car[j+1].name;
            car[j].serialnum =car[j+1].serialnum;
            car[j].regnum = car[j+1].regnum;
            car[j].year = car[j+1].year;
            
         }
         vivod++;
     }

    for (int i = 1; i <= k-vivod; i++){
        cout << i << "." << endl;
        cout << car[i].name << endl;
        cout << car[i].serialnum << endl;
        cout << car[i].regnum << endl;
        cout << car[i].year << endl;
        cout << endl;
    }
    cout << "Enter regestration num for search: ";
    int num;
    cin >> num;
    int pos=1;
    
    for (int i = 1; i <= k-vivod; i++)
    {
        if ( car[i].regnum != num)
        {
            pos++;
        }
        else{
            break;
        }
    }
    cout << pos << endl;
    cout << "Enter car spec: " << endl;
    cout << "Enter car name: "; cin >> car[pos+1].name; cout << endl;
    cout << "Enter serial num: "; cin >> car[pos+1].serialnum; cout << endl;
    cout << "Enter regestration num: "; cin >> car[pos+1].regnum; cout << endl;
    cout << "Enter year: "; cin >> car[pos+1].year; cout << endl;

    for (int i = 1; i<=pos; i++)
    {
        cout << i << "." << endl;
        cout << car[i].name << endl;
        cout << car[i].serialnum << endl;
        cout << car[i].regnum << endl;
        cout << car[i].year << endl;
        cout << endl;
    }
    
        cout << pos+1 << "." << endl;
        cout << car[pos+1].name << endl;
        cout << car[pos+1].serialnum << endl;
        cout << car[pos+1].regnum << endl;
        cout << car[pos+1].year << endl;
        cout << endl;
    
            
    for (int i = pos+2; i<=k-vivod+1; i++)
    {
        cout << i << "." << endl;
        cout << car[i].name << endl;
        cout << car[i].serialnum << endl;
        cout << car[i].regnum << endl;
        cout << car[i].year << endl;
        cout << endl;
    }
     
    return 0;

}