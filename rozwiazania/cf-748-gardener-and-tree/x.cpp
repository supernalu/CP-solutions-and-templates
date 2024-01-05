#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 4e5 + 10;
constexpr int INF = 1e9 + 10;

int t, n, k;

vector<int> adj[MAXN];

int dist[MAXN];

void bfs(vector<int> st)
{
    queue<int> q;

    for (auto v : st)
    {
        q.push(v);
        dist[v] = 1;
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
        {
            if (dist[u] != INF)
                continue;

            dist[u] = dist[v]+1;
            q.push(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        

        for (int i = 1; i < n; i++)
        {
            int a, b;

            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);

            dist[i] = INF;
        }
        dist[n] = INF;
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }


        vector<int> s;

        for (int i = 1; i <= n; i++)
        {
            if(adj[i].size() <= 1)
            {
                s.push_back(i);
            }
        }

        bfs(s);

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] > k)
                res++;
        }

        cout << res << '\n';


    }
}