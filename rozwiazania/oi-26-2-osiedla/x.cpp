#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

struct edge{
    int u;
    int id;
    char skier;
};

int n, m;
vector<edge> adj[MAXN];
vector<int> adj2[MAXN];
vector<int> revAdj[MAXN];
vector<bool> vis(MAXN, 0);
vector<bool> done(MAXN, 0);
char skierowania[MAXN];

void dfs(int v)
{
    //cout << v << ' ';
    vis[v] = 1;

    for (int i = adj[v].size()-1; i >= 0; i--)
    {
        edge u = adj[v][i];

        if (done[u.id])
        {
            adj[v].pop_back();
            continue;
        }
        adj2[v].push_back(u.u);
        revAdj[u.u].push_back(v);
        done[u.id] = 1;
        skierowania[u.id] = u.skier;
        if (!vis[u.u])
            dfs(u.u);

        adj[v].pop_back();
    }
    //cout << v << ' ';
}

vector<int> topo;
void topoSort(int v)
{
    vis[v] = 1;

    for (auto u : adj2[v])
    {
        if (vis[u])
            continue;

        topoSort(u);
    }
    topo.push_back(v);
}
void revDfs(int v)
{
    vis[v] = 1;

    for (auto u : revAdj[v])
    {
        if (vis[u])
            continue;

        revDfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b; cin >> a >> b;

        edge tmp1; tmp1.u = b; tmp1.id = i; tmp1.skier = '>';
        adj[a].push_back(tmp1);

        edge tmp2; tmp2.u = a; tmp2.id = i; tmp2.skier = '<';
        adj[b].push_back(tmp2);
    }

    for (int i = 1;  i <= n; i++)
    {
        if (!vis[i])
            dfs(i);    
    }

    vis.assign(MAXN, 0);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            topoSort(i);
    reverse(topo.begin(), topo.end());

    /*
    for (auto v : topo)
        cout << v << ' ';
    */

    vis.assign(MAXN, 0);
    int il = 0; 

    for (auto i : topo)
    {
        if (vis[i])
            continue;
        il++;
        revDfs(i);
    }

    cout << il << '\n';
    for (int i = 1; i <= m; i++)
        cout << skierowania[i];
    
}