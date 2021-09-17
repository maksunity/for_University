#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n = 9; //можно и через cin сделать не так важно
	//Это кол-во дорог между пунктами

	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < n; i++)
	{
		int a, b, d;
		cout << "Enter first apex: " << endl;
		cin >> a;
		cout << endl;
		cout << " Enter second apex: " << endl;
		cin >> b;
		cout << endl;
		cout << "Distance: " << endl;
		cin >> d;
		v[a][b] = v[b][a] = d;
	}

	bool visit[1000];
	int dist[1000];

	for (int i = 0; i < n; i++)
	{

		visit[i] = false;
		dist[i] = 1000000;
	}
	dist[1] = 0;
	visit[1] = true;

	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int ver = q.front();
		q.pop();

		for (int j = 1; j < v[ver].size(); j++)
		{
			if (!visit[j] && v[ver][j] && v[ver][j] + dist[ver] < dist[j])
			{

				dist[j] = v[ver][j] + dist[ver];
				q.push(j);
			}

			visit[j] = 0;
		}
	}
	for (int j = 1; j < 7; j++)
	{
		cout << dist[j] << " ";
	}
	return 0;
}
