#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 505;
constexpr long long INF = 1e18;

int n, m, q;



vector<vector<long long>> dist(MAXN, vector<long long> (MAXN, INF));

void bellman_ford()
{
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
        
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}

int main()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= m; i++)
    {
        int a, b; long long c;
        cin >> a >> b >> c;

        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    bellman_ford();

    for (int i = 1; i <= q; i++)
    {
        int d, e;

        cin >> d >> e;
        if (dist[d][e] == INF) 
        {
            cout << "-1\n";
            continue;
        }
        cout << dist[d][e] << endl;
    }

}