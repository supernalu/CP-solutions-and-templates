#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

constexpr long long MOD = 1e9+7;

int n, m;

vector<int> adj[MAXN];

vector<int> an_adj[MAXN];

int vis[MAXN];

vector<int> topo;

void topo_sort(int v)
{
    if (vis[v]) return;

    vis[v] = 1;

    for (auto u : adj[v])
        topo_sort(u);
    
    topo.push_back(v);
}

long long dp[MAXN];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        an_adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])        
            topo_sort(i);        
    }

    reverse(topo.begin(), topo.end());
    /*
    for (int i = 0; i < n; i++)
        cout << topo[i] << ' ';
    cout << endl;   
    */

    dp[1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (auto j : an_adj[topo[i]])
        {
            //cout << j << ' ';
            dp[topo[i]] += dp[j];
        }
        //cout << endl;
        dp[topo[i]] = dp[topo[i]]%MOD;
    }
    /*
    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
    */
   cout << dp[n];
    




}