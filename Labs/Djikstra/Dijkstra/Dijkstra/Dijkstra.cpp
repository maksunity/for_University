
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>

using namespace std;
int main()
{
	int n = 9;

	vector <vector<int>> v(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < n; i++) {
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

	for (int i = 0; i < n; i++) {

		visit[i] = false;
		dist[i] = INT_MAX;

	}
	dist[1] = 0;
	visit[1] = true;

	queue<int>q;
	q.push(1);

	while (!q.empty()) {
		int vetrex = q.front();
		q.pop();

		for (int j = 1; j < v[vetrex].size(); j++) {
			if (!visit[j] && v[vetrex][j] && v[vetrex][j] + dist[vetrex] < dist[j]) {

				dist[j] = v[vetrex][j] + dist[vetrex];
				q.push(j);
			}

			visit[j] = 0;
		}
	}

	for (int j = 1; j < 7; j++) {
		cout << dist[j] << " ";
	}

	return 0;
}
