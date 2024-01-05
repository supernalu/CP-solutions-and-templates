#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10; 

int n;

vector<int> adj[MAXN];

int il[MAXN];

int dfs(int v)
{
    if (adj[v].size() == 0)
    {
        il[1]++;

        return 1;
    }

    int res = 0;

    for (auto u : adj[v])
    {
        res += dfs(u);
    }

    il[res]++;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int a;

        cin >> a;

        adj[a].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < il[i]; j++)
        {
            cout << i << ' ';
        }
    }
}