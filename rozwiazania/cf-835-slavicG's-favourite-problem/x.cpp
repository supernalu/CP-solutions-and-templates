#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int t, n, a, b;
vector<pair<int, int>> adj[MAXN];
int odl[MAXN][2];
bool vis[MAXN][2];
map<int, bool> rev;
void bfs(int st, int it)
{
    queue<int> q;
    q.push(st);
    vis[st][it] = 1;
    rev[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (it == 0 && v == b)
            continue;
        for (auto u : adj[v])
        {
            if (vis[u.first][it])
                continue;
            vis[u.first][it] = 1;
            odl[u.first][it] = odl[v][it] xor u.second;
            q.push(u.first);
            rev[odl[u.first][it]] = it;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            odl[i][0] = 0;
            odl[i][1] = 0;
            vis[i][0] = 0;
            vis[i][1] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            int v, u, c; cin >> v >> u >> c;
            adj[v].push_back({u, c});
            adj[u].push_back({v, c});
        }
        bfs(a, 0);
        bfs(b, 1);
        bool res = 0;
        for (int i = 1; i <= n; i++)
        {
            //cout << odl[i][0] << ' ' << rev[odl[i][0]] << '\n';
            if (i == b && odl[i][0] == 0)
            {
                
                res = 1;
            }
            else if (i != b && rev[odl[i][0]])
            {
                
                res = 1;
            }
        }

        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}