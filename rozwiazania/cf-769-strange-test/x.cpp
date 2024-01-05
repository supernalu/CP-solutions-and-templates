#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;
constexpr int INF = 1e9 + 10;

int t;

int a, b;

int dist[MAXN];

void bfs(int st)
{
    queue<int> q;

    q.push(st);
    dist[st] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if ()
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> a >> b;

        for (int i = a+1; i <= b; i++)
        {
            dist[i] = INF;
        }

    }
}