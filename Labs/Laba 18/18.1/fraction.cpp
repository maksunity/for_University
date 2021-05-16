#include <iostream>
#include <cmath>
#include "fraction.h"

using namespace std;
double x_first, x_second, y_first, y_second;

void Init(double x1, double x2, double y1, double y2)
{
    x_first = x1;
    x_second = x2;
    y_first = y1;
    y_second = y2;
}


void Read()
{
    cout << endl;
    cout << "Enter first point: " << endl;
    cin >> x_first;
    cout << endl;
    cin >> y_first;
    cout << endl << "Enter second point: " << endl;
    cin >> x_second;
    cout << endl;
    cin >> y_second;
}

void Show()
{
    cout << "First point: " << x_first << " " << y_first << endl;
    cout << "First point: " << x_second << " " << y_second << endl;
}

float Distance()
{
    return sqrt ( pow((x_second-x_first),2) + pow((y_second-y_first),2) );
}
