#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5010;
constexpr int INF = 1e9 + 10;

int n, m, q;
vector<int>adj[MAXN];
vector<int>odl[MAXN][2];

void bfs(int st)
{
    queue<pair<int, int>> q;
    q.push({st, 0});
    odl[st][0][st] = 0;

    while (!q.empty())
    {
        int v = q.front().first;
        int parity = q.front().second;
        q.pop();

        for (auto u : adj[v])
        {
            int a = min(st, u), b = max(st, u);
            if (odl[b][(parity+1)%2][a] != INF)
                continue;

            odl[b][(parity+1)%2][a] = odl[max(st, v)][parity][min(v, st)]+1;
            q.push({u, (parity+1)%2});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;

    while (m--)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int v = 1; v <= n; v++)
    {
        odl[v][0].assign(v+1, INF);
        odl[v][1].assign(v+1, INF);
    }
    for (int i = 1; i <= n; i++)
        bfs(i);

    while (q--)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a < b)
            swap(a, b);

        int tmp = odl[a][c%2][b];

        if (adj[a].size() == 0 || c < tmp)
        {
            cout << "NIE\n";
            continue;
        }
        
        cout << "TAK\n";
    }
}