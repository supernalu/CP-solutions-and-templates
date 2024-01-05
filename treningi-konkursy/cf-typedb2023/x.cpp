#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];

vector<int> adj[MAXN];
bool vis[MAXN];

long long vis2[MAXN];
int parent[MAXN];

void bfs()
{
    queue<int>q;

    for (int i = 1; i <= n; i++)
        vis2[i] = 1e9;
    for (int i = 1; i <= n; i++)
        parent[i] = -1;

    q.push(0); q.push(n+1);
    vis2[0] = 0; vis2[n+1] = 0;
    parent[0] = 0; parent[n+1] = n+1;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
        {
            if (vis2[u] != 1e9)
                continue;
            vis2[u] = vis2[v] + 1;
            parent[u] = parent[v];
            q.push(u);
        }
    }
}

long long gl[MAXN];

void dfs(int v)
{
    gl[v]++;
    for (auto u : adj[v])
    {
        if (gl[v]!= -1)
            continue;

        dfs(u);
        gl[v] += gl[u];
    }
    
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i <= n+1; i++)
        {
            adj[i].clear();
            vis[i] = 0;
            gl[i] = -1;
        }

        a[0] = 0; a[n+1] = n+1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            adj[min(n+1, max(i +a[i], 0))].push_back(i);
        }
        int v = 1;

        while (!vis[v])
        {
            vis[v] = 1;
            v = min(n+1, max(v +a[v], 0));
        }

        /*
        for (int i = 1; i <= n; i++)
            cout << vis[i] << ' ';
        cout << '\n';
        */
        

        bfs();
        dfs(n+1);
        dfs(0);

        /*
        for (int i = 1; i <= n; i++)
        {
            cout << vis2[i] << ' ';
        }
        cout << '\n';
        */
        

        long long il[3];
        il[0] = 0; il[1] = 0; il[2] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (parent[i] == -1)
                il[0]++;
            else if (parent[i] == 0)
                il[1]++;
            else
                il[2]++;
        }

        //cout << il[0] << il[1] << il[2];
        

        long long res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                res += (long long)(n+1);

                res += il[1];
                res += il[2];

                if (parent[i] == 0)
                {
                    res -= (gl[i]);
                }
                if (parent[i] == n+1)
                {
                    res -= (gl[i]);
                }
                //cout << res << ' ';
            }
            else if (vis[i] == 0)
            {
                res += (long long)(2*n+1);
            }
        }
        cout << res << '\n';
    }
}