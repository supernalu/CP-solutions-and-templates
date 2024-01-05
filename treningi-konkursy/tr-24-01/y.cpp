#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e3 + 10;

int n, s, m;
vector<int> adj[MAXN];
bool road[MAXN][MAXN];
vector<bool> tmp(MAXN, 0);
vector<int> topo;
vector<bool> vis(MAXN, 0);
vector<bool>con(MAXN, 0);
vector<int> dp(MAXN, 1e9);

void toposort(int v)
{
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        vis[u] = 1;
        toposort(u);
    }
    topo.push_back(v);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s >> m;

    for (int i = 1; i <= s; i++)
    {
        int a, b; cin >> a >> b; 

        dp[a] = b;
        con[a] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r, k; cin >> l >> r >> k;
        vector<int> tmp2;

        for (int j = l; j <= r; j++)
        {
            tmp[i] = 0;
        }

        for (int j = 1; j <= k; j++)
        {
            int a; cin >> a;
            tmp[a] = 1;
            tmp2.push_back(a);
        }
        for (auto u : tmp2)
        {
            for (int j = l; j <= r; j++)
            {   
                if (tmp[j] || road[u][j])
                    continue;
                adj[u].push_back(j); 
                road[u][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        toposort(i);
    }

    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    reverse(topo.begin(), topo.end());
        
    for (auto v : topo)
    {
        vis[v] = 1;

        for (auto u : adj[v])
        {
            if (vis[u])
            {
                cout << "NIE\n";
                return 0;
            }
        }
    }

    for (auto v : topo)
    {
        for (auto u : adj[v])
        {
            if (con[u])
            {
                if (dp[v] <= dp[u])
                {
                    cout << "NIE\n";
                    return 0;
                }
                continue;
            }
            dp[u] = min(dp[v]-1, dp[u]);
        }
    }

    cout << "TAK\n";
    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
}