#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 1e6 + 10;

int n;
vector<int> adj[MAXN];
ll siz[MAXN];
ll dp[MAXN];
bool vis[MAXN];

void countSize(int v)
{
    siz[v] = 1;
    for (auto u : adj[v])
    {
        if (siz[u] == 0)
            countSize(u);
        siz[v] += siz[u];
    }
}
void solve(int v)
{
    vector<ll> tmp;
    for (auto u : adj[v])
    {
        if (vis[u])
        continue;
        
        vis[u] = 1;
        solve(u);
        dp[v]+= dp[u];
        dp[v]+= siz[u];
        tmp.push_back(siz[u]);
    }
    ll sum = 0;
    ll sumusMaximus = 0;

    for (auto i : tmp)
        sum += i;
    for (auto i : tmp)
        sumusMaximus += (sum-i)*i;
    sumusMaximus /= 2;
    dp[v]+= sumusMaximus;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b); 
        adj[b].push_back(a);
    }

    ll res = 2*n*n, id;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            siz[i] = 0;
            dp[i] = 0;
            vis[i] = 0;
        }
        countSize(i);
        vis[i] = 1;
        solve(i);

        ll tmp = dp[i];

        cout << tmp << '\n';

        if (tmp < res)
        {
            res = tmp;
            id = i;
        }
    }

    cout << id << ' ' << res;
    return 0;
}