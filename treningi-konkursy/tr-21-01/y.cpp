#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int n;
vector<int> adj[MAXN];
int deep[MAXN];
int ancestor[MAXN][30];

void initiation(int v)
{
    for (auto u : adj[v])
    {
        if (deep[u] != 0)
            continue;
        ancestor[u][0] = v;
        deep[u] = deep[v]+1;
        initiation(u);
    }
}

int solve(int k)
{
    int res = 0;

    for (int i = 1; i <= n; i++)
        deep[i] = 0;
    deep[k] = 1;
    for (int i = 0; i < 30; i++)
        for (int u = 1; u <= n; u++)
            ancestor[u][i] = 0;
    
    initiation(k);
    for (int i = 1; i < 30; i++)
        for (int v = 1; v <= n; v++)
            ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];  

    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            int v = i, u = j;
            if (deep[v] > deep[u])
                swap(u, v);
            
            for (int k = 29; deep[u] > deep[v];k--)
            {
                if (deep[ancestor[u][k]] < deep[v])
                    continue;

                u = ancestor[u][k];
            }
            //cout << v << ' ' << u << '\n';

            if (u != v)
                res += 2;
            else
                res++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (n <= 1e6 + 10)
    {
        int res = 2*n*n, id;
        for (int i = 1; i <= n; i++)
        {
            int tmp = solve(i);

            //cout << tmp << ' ';

            if (tmp < res)
            {
                res = tmp;
                id = i;
            }
        }

        cout << id;
        return 0;
    }


}