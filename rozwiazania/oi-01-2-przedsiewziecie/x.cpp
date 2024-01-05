#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

vector<int> adj[MAXN];
long long cost[MAXN];
bool vis[MAXN];
bool poss = 1;
vector<int> topo;
long long dp[MAXN];
long long dp2[MAXN];




void dfs(int v)
{
    if (vis[v])
        return;

    vis[v] = 1;

    for (auto u : adj[v])
        dfs(u);

    topo.push_back(v);
}

int dyn()
{
    long long re = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int j = topo[i];

        dp[j] += cost[j];

        re = max(dp[j], re);

        for (auto u : adj[j])
        {
            dp[u] = max(dp[u], dp[j]);
        }
    }

    return re;
}

void calculatetimeToFinish() {
        for (int i = topo.size() - 1; i >= 0; --i) {
            int v = topo[i];
            for (auto u : adj[v]) {
                dp2[v] = max(dp2[v], dp2[u] + cost[u]);
            }
        }
    }


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k;

        cin >> cost[i] >> k;

        for (int j = 1; j <= k; j++)
        {
            int a;

            cin >> a;

            adj[a].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }


    reverse(topo.begin(), topo.end());

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (auto u: adj[topo[i]])
        {
            if (vis[u])
            {
                poss = 0;
                break;
            }
        }
        vis[topo[i]] = 1;
    }

    int res = dyn();

    calculatetimeToFinish();

    if (poss)
        cout << res << "\n";

    int q;

    cin >> q;

    while (q--)
    {
        int a, b;

        cin >> a >> b;

        if (!poss)
            continue;

        if (dp[a] + dp2[a] + b > res)
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }

    if (!poss)
        cout << "CYKL";




}