#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

vector<int> adj[MAXN];

bool vis[MAXN];

int dp[MAXN];

void dfs(int i)
{
    vis[i] = true;

    if (adj[i].empty())
        return;

    for (auto j : adj[i])
    {
        dfs(j);

        dp[i] += dp[j] + 1;
    }    
}

int main()
{
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int a;

        cin >> a;

        adj[a].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
}