#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;
vector<int> adj[MAXN];

bool solve(int v)
{
    if (adj[v].size() == n-1)
        return 0;
    else
        return 1;   
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int m; cin >> m;

        while (m--)
        {
            int a; cin >> a;
            adj[a].push_back(i);
        }
    }
    vector<int> res;

    for(int i = 1; i <= n; i++)
    {
        if (solve(i))
            res.push_back(i);
    }

    cout << res.size() << ' ';

    for (auto i : res)
        cout << i << ' ';

    
}