#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int  n, m;

vector <int> adj[MAXN];

vector <int> an_ad[MAXN];

int num_ad[MAXN];

vector<int> topo;

void topo_sort()
{
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (num_ad[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        topo.push_back(v);

        for (auto u : adj[v])
        {
            num_ad[u]--;

            if (num_ad[u] == 0)
                q.push(u);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        an_ad[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)    
        num_ad[i] = an_ad[i].size();
    /*
    for (int i = 1; i <= n; i++)
        cout << num_ad[i] << ' ';
    */

    topo_sort();

    for (int i = 1; i <= n; i++)
    {
        if (num_ad[i] != 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (auto i : topo)
    {
        cout << i << ' ';
    }

}