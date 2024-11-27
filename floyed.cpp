#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 100;
int dist[MAX_N][MAX_N];

void floydWarshall(int n)
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = w;
    }

    floydWarshall(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
