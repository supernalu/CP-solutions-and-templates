#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, m;

vector<int> adj[MAXN];

bool vis[MAXN];

int dp[MAXN];

vector<int> topo;

int parent[MAXN];

void topo_sort(int v)
{
    if(vis[v])
        return;
    
    vis[v] = 1;

    for (auto u : adj[v])
    {
        topo_sort(u);
    }

    topo.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
    }

    topo_sort(1);

    reverse(topo.begin(), topo.end());

    parent[1] = 1;

    dp[1] = 1;

    for (auto v : topo)
    {
        for (auto u : adj[v])
        {
            dp[u] = max(dp[u], dp[v]+1);

            if (dp[u] == dp[v]+1)
                parent[u] = v;
        }       
    }

    if (dp[n] > 0)
    {
        cout << dp[n] << '\n';

        vector<int> odt;

        odt.push_back(n);

        int v = parent[n];

        while (parent[v] != v)
        {
            odt.push_back(v);
            v = parent[v];
        }

        odt.push_back(1);

        reverse(odt.begin(), odt.end());

        for (auto i : odt)
        {
            cout << i << ' ';
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }








}