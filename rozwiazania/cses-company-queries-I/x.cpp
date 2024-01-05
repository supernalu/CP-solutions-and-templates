#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n, q;

vector <int>adj[MAXN];

int ancestor[MAXN][40];

int parent[MAXN];

void dfs(int v)
{


    for (int u : adj[v])
    {
        if (parent[u] == 0)
        {
            parent[u] = v;

            dfs(u);
        }
    }
}

void preprocessing()
{
    parent[1] = -1;

    dfs(1);

    /*
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << ' ';
    }

    cout << endl;
    */

    for (int i = 1; i <= n; i++)
    {
        ancestor[i][1] = parent[i];
    }

    for (int i = 2; i <= 40; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];
        }
    }

    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << ancestor[i][j] << ' ';
        }
        cout << endl;
    }
    */
    
    
}

int query(int a, int b)
{

    while (b != 0)
    {
        int torch = b & -b;

        int l = log2(torch) + 1;

        a = ancestor[a][l];

        b -= torch;
    }

    if (a < 1)
        return -1;
    else
        return a;
}

int main()
{
    cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int a;

        cin >> a;

        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    preprocessing();

    for (int i = 1; i <= q; i++)
    {
        int a, b;

        cin >> a >> b;

        cout << query(a, b) << '\n';
    }


}