#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void bellm(int V, int E, int e[][3], int s) {
    int d[100];
    for (int i = 0; i < V; ++i)
        d[i] = INF;
    d[s] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = e[j][0];
            int v = e[j][1];
            int w = e[j][2];
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
            }
        }
    }
    for (int j = 0; j < E; ++j) {
        int u = e[j][0];
        int v = e[j][1];
        int w = e[j][2];
        if (d[u] != INF && d[u] + w < d[v]) {
            cout << "Graph contains a negative weight cycle.\n";
            return;
        }
    }
    cout << "Shortest distances from vertex " << s << ":\n";
    for (int i = 0; i < V; ++i) {
        if (d[i] == INF)
            cout << i << ": INF\n";
        else
            cout << i << ": " << d[i] << '\n';
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    int e[1000][3];
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i][0] = u;
        e[i][1] = v;
        e[i][2] = w;
    }

    int s;
    cin >> s;

    bellm(V, E, e, s);

    return 0;
}


