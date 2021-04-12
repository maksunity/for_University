#include <iostream> //Вариант 21 (9)
#include <string>
#include <math.h>
using namespace std;

class Distance {
    public:
        double x; 
        double y;
        double x1; 
        double y1;  

        public:
        void Start(){
            cout << "Enter coordinates: " << endl;
        }

        void SetX(double posX){
            cin >> posX;
            x = posX;
        }

        double GetX(double x){
            return x;
        }

        void SetX1(double posX1){
            cin >> posX1;
            x1 = posX1;
        }

        void SetY(double posY){
            cin >> posY;
            y = posY;
        }

        void SetY1(double posY1){
            cin >> posY1;
            y1 = posY1;
        }

        void Dist(double x, double y, double x1, double y1){
            double d;
            SetX(x);
            SetY(y);
            SetX1(x1);
            SetY1(y1);
            d = sqrt( ((pow((x-x1),2)))   + ((pow((y-y1),2))) );
            cout << d;
        }
};


int main()
{
    double d;
    Distance First;
    First.Dist(2,4,6,8);
    return 0;
}