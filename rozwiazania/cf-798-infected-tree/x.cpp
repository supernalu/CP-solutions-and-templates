#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

vector<int> adj[MAXN];

int t, n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
            adj[i].clear();

        for (int i = 1; i < n; i++)
        {
            int a, b;

            cin >> a >> b;

            adj[b].push_back(a);
            adj[a].push_back(b);
        }


    }
}