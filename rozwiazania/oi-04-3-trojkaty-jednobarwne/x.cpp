#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN  = 1010;

vector<int> adj[MAXN];

int n, m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int num = (n*(n-1)*(n-2))/6;

    int il = 0;

    for (int i = 1; i <= n; i++)
    {
        il += adj[i].size()*(n-1-adj[i].size());
    }
    il /= 2;

    cout << num - il;
}