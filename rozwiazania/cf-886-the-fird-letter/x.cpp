#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int t, n, m;
vector<pair<int, long long>> adj[MAXN];
long long id[MAXN];
bool vis[MAXN];
int a[MAXN], b[MAXN]; long long c[MAXN];

void dfs(int v)
{
    vis[v] = 1;

    for (auto u : adj[v])
    {
        if (vis[u.first])
            continue;
        
        id[u.first] = id[v] + u.second;
        dfs(u.first);
    }
}

void topo(int v)
{

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }

        for (int i = 1; i <= m; i++)
        {
             cin >> a[i] >> b[i] >> c[i];

            adj[a[i]].push_back({b[i], c[i]});
            adj[b[i]].push_back({a[i], -c[i]});
        }

        for (long long i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            
            id[i] = 0;

            dfs(i);
        }

        bool res = 1;
        
        for (int i = 1; i <= m; i++)
        {
            if (id[a[i]]-id[b[i]] != -c[i])
                res = 0;
        }

        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}