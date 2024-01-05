#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 7e3 + 10;

int n;

vector<int> adj[MAXN];

vector<bool> vis(MAXN, 0);

struct rec
{
    int a;
    int b;
    int c;
    int d;
};

rec x[MAXN];

bool same(rec q, rec w)
{
    int xMax = min(q.c, w.c);
    int xMin = max(q.a, w.a);
    int yMax = min(q.d, w.d);
    int yMin = max(q.b, w.b);

    if ((xMax - xMin)*(yMax - yMin) >= 0 && (xMax - xMin)+(yMax - yMin) > 0)
    {
        return 1;
    }

    return 0;

}

void bfs(int st)
{
    queue<int> q;

    q.push(st);

    vis[st] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
        {
            if (!vis[u])
            {
                q.push(u);

                vis[u] = 1;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].a >> x[i].b >> x[i].c >> x[i].d;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;

            if (same(x[i], x[j]))
            {
                adj[i].push_back(j);
                
            }
        }
    }


    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            res++;

            bfs(i);
        }
    }

    cout << res;
}