#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<vector<bool>> matrix;
int color[10];

bool RepeatColor(int cur)
{
    for (int i = 0; i < 10; i++)
    {
        if (matrix[cur][i] && color[cur] == color[i])
        {
            return false;
        }
    }
    return true;
}

void coloring()
{
    for (int i = 0; i < 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            color[i] = j;
            if (RepeatColor(i))
            {
                break;
            }
            color[i] = 0;
        }
}

int main()
{
    fstream stream("f1.txt", ios::in);
    if (stream)
    {
        for (int i = 0; i < 10; i++)
        {
            vector<bool> o;
            for (int j = 0; j < 10; j++)
            {
                int k;
                stream >> k;
                o.push_back(k);
            }
            matrix.push_back(o);
        }
        coloring();
        for (int i = 0; i < 10; i++)
        {
            cout << i << " - " << color[i] << endl;
        }
    }
}