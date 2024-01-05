#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;
int res = 0, n;

vector<int> adj[MAXN];

bool visited[MAXN];

void bfs(int k)
{
    queue<int> q;
    q.push(k);
    visited[k] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto u : adj[v])
        {
            if (visited[u])
                continue;

            q.push(u);
            visited[u] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;

        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            res++;
        }
    }

    cout << res;
}