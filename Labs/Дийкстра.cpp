#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter kolvo dorog: ";
    cin >> n;
    vector<vector<int>> v (n+1, vector<int> (n+1));
    for (int i=0; i<n ; i++)
    {
        int first, second, distance;
        cout << "1st apex: ";
        cin >> first;
        cout << "2nd apex: ";
        cin >> second;
        cout << "Dist: ";
        cin >> distance;
        v[first][second] = v[second][first] = distance;
    }

    bool visit [128];
    int dist [256];

    for (int i=0; i<n; i++)
    {
        visit [i] = false;
        dist[i] = 1000000; 
    }

    visit[1] = true;
    dist[1] = 0;

    queue <int> q;
    q.push(1);

    while (!q.empty())
    {
        int ver = q.front();
        q.pop();
        for (int j = 1; j < v[ver].size(); j++)
        {
            if (!visit[j] && v[ver][j] && v[ver][j]+dist[ver]< dist[j])
            {
                dist[j] = v[ver][j] + dist[ver];
                q.push(j);
            }
            visit[j]=0;
        }
    }
    for (int j = 1; j<5; j++)
    {
        cout << dist[j] << " ";
    }
}