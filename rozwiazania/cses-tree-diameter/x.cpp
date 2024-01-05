#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

vector <int> adj[MAXN];

vector<int> odl(MAXN, -1);

void dfs(int v)
{
    for (auto u : adj[v])
    {
        if (odl[u] == -1)
        {
            odl[u] = odl[v] + 1;

            dfs(u);
        }
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

    odl[1] = 0;

    dfs(1);

    int res = -1, id;

    for (int i = 1; i <= n; i++)
    {
        if (odl[i] > res)
        {
            res = odl[i];

            id = i;
        }

        odl[i] = -1;
    }

    odl[id] = 0;

    dfs(id);

    res = -1;

    for (int i = 1; i <= n; i++)
        res = max(res, odl[i]);
    
    cout << res;

}