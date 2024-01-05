#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e3 + 10;
constexpr int INF = 1e9 + 10;

int n;

vector<int> moves[MAXN];
vector<int> adj[MAXN];
vector<int> odl(MAXN, INF);
int deep[MAXN];
bool vis[MAXN];

void bfs()
{
    queue<int> q;

    q.push(1);
    deep[1] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
        {
            if (deep[u] != INF)
                continue;

            deep[u] = deep[v]+1;
            q.push(u);
        }
    }
}

void miniBfs(int k)
{
    odl.assign(MAXN, INF);

    queue<int> q;

    q.push(k);
    odl[k] = 0;
    

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (odl[v] == 3)
            continue;

        for (auto u : adj[v])
        {
            if (odl[u] != INF)
                continue;

            odl[u] = odl[v]+1;
            moves[k].push_back(u);
            q.push(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        deep[i] = INF;
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    deep[n] = INF;  
    
    bfs();

    for (int i = 1; i <= n; i++)
        miniBfs(i); 
        
    int v = 1;
    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        res.push_back(v);
        vis[v] = 1;

        int maxi = -1, id;

        for (auto u : moves[v])
        {
            if (vis[u])
                continue;

            if (maxi < deep[u])
            {
                maxi = deep[u];
                id = u;
            }
        }
        v = id;
    }

    for (auto v : res)
        cout << v << '\n';
}