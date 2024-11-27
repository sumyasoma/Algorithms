#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void dijk(int n, int s, int adj[][100], int w[][100], int e[]) {
    int d[100];
    bool vis[100] = {0};
    for (int i = 0; i < n; ++i)
        d[i] = INF;
    d[s] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }
        if (d[u] == INF) break;
        vis[u] = true;

        for (int j = 0; j < e[u]; ++j) {
            int v = adj[u][j];
            int wt = w[u][j];
            if (d[u] + wt < d[v]) {
                d[v] = d[u] + wt;
            }
        }
    }

    cout << "Shortest distances from vertex " << s << ":\n";
    for (int i = 0; i < n; ++i) {
        if (d[i] == INF)
            cout << i << ": INF\n";
        else
            cout << i << ": " << d[i] << '\n';
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int adj[100][100];
    int w[100][100];
    int e[100] = {0};

    for (int i = 0; i < m; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][e[u]] = v;
        w[u][e[u]] = wt;
        e[u]++;
    }

    int s = 0;
    dijk(n, s, adj, w, e);
    return 0;
}
