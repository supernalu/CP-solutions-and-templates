#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

int n;

vector<int> adj[MAXN];

int ancestor[MAXN];

int dp[MAXN];

int res;

void dfs(int v, int deep, int il)
{
    il += adj[v].size();

    il--;

    int tmp;

    if (il%deep == 0)
        tmp = il/deep;
    else
    {
        tmp = (il/deep) +1;
    }

    //cout << v << ' ' << ancestor[v] << ' ' <<  tmp << endl;



    dp[v] = max(dp[ancestor[v]], tmp);

    res = max(res, dp[v]);

    for (auto u : adj[v])
    {
        if (ancestor[v] == u)
            continue;

        ancestor[u] = v;

        dfs(u, deep + 1, il);
    }
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n-1; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ancestor[1] = 0;

    dp[0] = 0;

    adj[1].push_back(0);

    //cout << endl;

    dfs(1, 1, 0);


    /*
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << ' ';
    }
    */

    

    cout << res;


}