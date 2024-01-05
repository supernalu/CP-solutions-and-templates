#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5010;
constexpr short INF = 31000;

int n, m, q;
vector<short>adj[MAXN];
short odl[MAXN][MAXN][2];

void bfs(int st)
{
    queue<pair<short, short>> q;
    q.push({st, 0});
    odl[st][st][0] = 0;

    while (!q.empty())
    {
        int v = q.front().first;
        int parity = q.front().second;
        q.pop();

        for (auto u : adj[v])
        {
            if (odl[st][u][(parity+1)%2] != INF)
                continue;

            odl[st][u][(parity+1)%2] = odl[st][v][parity]+1;
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
        short a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int v = 1; v <= n; v++)
    {
        for (int u = 1; u <= n; u++)
        {
            odl[v][u][0] = INF;
            odl[v][u][1] = INF;
        }
    }
    for (int i = 1; i <= n; i++)
        bfs(i);

    while (q--)
    {
        int a, b, c; cin >> a >> b >> c;

        short tmp = odl[a][b][c%2];

        if (c > (int)INF)
            c = (int)INF;
        short k = min((short)c, INF);

        if (adj[a].size() == 0 || k < tmp)
        {
            cout << "NIE\n";
            continue;
        }
        
        cout << "TAK\n";
    }
}