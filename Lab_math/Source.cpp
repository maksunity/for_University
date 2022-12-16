#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int p[1000];
int rk[1000];

struct edge
{
    int a, b, len;
    bool operator<(edge& other) {
        return len < other.len;
    }
};

void init_dsu() {
    for (int i = 0; i < 1000; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int get_way(int v) {
    if (p[v] == v) {
        return v;
    }
    else {
        return p[v] = get_way(p[v]); 
    }
}

bool merge(int a, int b) {
    int a1 = get_way(a);
    int b1 = get_way(b);

    if (a1 == b1) {
        return false;
    }
    else {
        if (rk[a1] < rk[b1]) {
            p[a1] = b1;
        }
        else if (rk[b1] < rk[a1]) {
            p[b1] = a1;
        }
        else {
            p[a1] = b1;
            rk[b1]++;
        }
        return true;
    }
}

int main()
{
    fstream stream("f1.txt", ios::in);
    if (stream)
    {
        int size;
        stream >> size;
        vector<edge> edges;
        for (int i = 0; i < size; i++)
        {
            edge o;
            stream >> o.a;
            stream >> o.b;
            stream >> o.len;
            edges.push_back(o);
        }
        sort(edges.begin(), edges.end());
        int mst_weight = 0;

        init_dsu();
        vector<edge> o;
        for (edge i : edges) {
            if (merge(i.a, i.b)) { 
                o.push_back(i);
            }
        }
        cout << "Tree: " << endl;
        for (edge i : o) {
            cout << i.a << " - " << i.b << " : " << i.len << endl;
        }
    }
}