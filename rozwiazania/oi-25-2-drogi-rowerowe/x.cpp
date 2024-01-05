#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e4 + 10;

int n;

int m;

vector<int> adj[MAXN];

vector<int> trans_adj[MAXN];

set<int> skl_adj[MAXN];

vector<bool> vis(MAXN, 0);

vector<int> topo;

vector<int> skl;

int skl_size[MAXN];

int v_s[MAXN];

int dp[MAXN];

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

void trans_dfs(int v)
{
    if (vis[v])
        return;

    vis[v] = 1;

    for (auto u :  trans_adj[v])
    {
        trans_dfs(u);
    }

    skl.push_back(v);
}

void topo_skl(int v)
{
    if (vis[v])
        return;

    vis[v] = 1;

    for (auto it = skl_adj[v].begin(); it != skl_adj[v].end(); it++)
    {
        topo_skl(*it);
    }

    topo.push_back(v);
}







int main()
{
    ios_base::sync_with_stdio(0);   cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);

        trans_adj[b].push_back(a);
    }


    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            topo_sort(i);
    }

    reverse(topo.begin(), topo.end());

    vis.assign(MAXN, 0);

    int k = 0;

    for (auto i : topo)
    {
        if (vis[i])
            continue;

        k++;

        trans_dfs(i);

        for (auto j : skl)
        {
            v_s[j] = k;

        }

        skl_size[k] = skl.size();

        skl.assign(0, 0);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (auto u : adj[i])
        {
            if (v_s[i] != v_s[u])
                skl_adj[v_s[u]].insert(v_s[i]);
        }
    }

    /*
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";

        for (auto it = skl_adj[i].begin(); it != skl_adj[i].end(); it++)
        {
            cout << *it << ' ';
        }

        cout << endl;
    }
    */
    

    topo.assign(0, 0);
    vis.assign(MAXN, 0);

    for (int i = 1; i <= k; i++)
    {
        if (!vis[i])
            topo_skl(i);
    }



    reverse(topo.begin(), topo.end());

    for (auto i : topo)
    {
        //cout << i << ' ';

        dp[i] += skl_size[i]-1;

        for (auto it = skl_adj[i].begin(); it != skl_adj[i].end(); it++)
        {
            dp[*it] += dp[i]+1;
        }
    }

    /*
    cout << endl;
    for (auto i : topo)
    {
        cout << dp[i] << ' ';
    }
    */

    for (int i = 1; i <= n; i++)
    {
        cout << dp[v_s[i]] << '\n';
    }



    










   




}