#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n, m;

vector<int> topo;

vector<int> adj[MAXN];

vector<bool> vis(MAXN, 0);

vector<int> dp(MAXN, 0);

void topoSort(int v)
{
    if (vis[v])
        return;

    vis[v] = 1;

    for (auto u : adj[v])
    {
        topoSort(u);
    }

    topo.push_back(v);
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            topoSort(i);
    }

    reverse(topo.begin(), topo.end());


    int res = 1e9+10, id = 0;

    for (int blokada = 1; blokada <= n; blokada++)
    {
        dp.assign(MAXN, 0);

        int tmp = 0;

        for (auto v : topo)
        {
            if (v == blokada)
                continue;

            for (auto u : adj[v])
            {
                dp[u] = max(dp[u], dp[v]+1);
            }           
        }

        for (int i = 1; i <= n; i++)
        {
            if (i == blokada)
                continue;

            
            tmp = max(tmp, dp[i]);
        }

        if (res > tmp)
        {
            res = tmp;

            id = blokada;
        }
    }

    cout << id << ' ' << res;
}