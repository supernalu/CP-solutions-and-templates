#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 10;

int n, m;

vector<int> adj[MAXN];

vector<int> trans_adj[MAXN];

vector<bool> vis(MAXN, 0);

vector<bool> trans_vis(MAXN, 0);

vector<int> res;

vector<int> topo;  

void dfs(int v)
{
    if (vis[v])
        return;

    vis[v] = 1;

    for (auto u : adj[v])
    {
        dfs(u);
    }
}

void trans_dfs(int v)
{

    if (trans_vis[v])
        return;

    trans_vis[v] = 1;

    for (auto u : trans_adj[v])
    {
        trans_dfs(u);
    }

}

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

        trans_adj[b].push_back(a);
    }

    if (n <= 5000 && m <= 5000)
    {
        for (int i = 1; i <= n; i++)
        {
            

            vis.assign(MAXN, 0);

            trans_vis.assign(MAXN, 0);

            dfs(i);

            trans_dfs(i);

            int j = 1;

            for ( ; j <= n; j++)
            {
                if (vis[j] || trans_vis[j])
                    continue;

                break;      
            }

            if (j == n+1)
            {
                res.push_back(i);
            }
        }
    }
    else
    {

    }

    cout << res.size() << '\n';

    for (auto i : res)
        cout << i << ' ';
}