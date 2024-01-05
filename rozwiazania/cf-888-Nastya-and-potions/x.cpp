#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

int t, n, k, p;
long long c[MAXN];
vector<int> adj[MAXN]; //revAdj[MAXN];
bool vis[MAXN], freee[MAXN];
long long dp[MAXN];

vector<int> topo;

void topoSort(int v)
{
    vis[v] = 1;

    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        topoSort(u);
    }

    //cout << v << ' ';
    topo.push_back(v);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {

        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            freee[i] = 0;
            dp[i] = 0;
            adj[i].clear();
        }
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        for (int i = 1; i <= k; i++)
        {
            cin >> p;
            freee[p] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            int m; cin >> m;

            while (m--)
            {
                int tmp; cin >> tmp;

                adj[i].push_back(tmp);
                //revAdj[tmp].push_back(i);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (freee[i])
            {
                dp[i] = 0;
                continue;
            }
            dp[i] = c[i];

        }

        topo.clear();

        for (int i = 1; i <= n; i++)
            vis[i] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            topoSort(i);
        }
        reverse(topo.begin(), topo.end());

       // for (int i = 0; i < n; i++)
            //cout << topo[i] << ' ';

        for (int i = n-1; i >= 0; i--)
        {
            int v = topo[i];

            if (adj[v].empty())
                continue;

            long long sum = 0; 

            for (auto u : adj[v])
                sum += dp[u];

            dp[v] = min(dp[v], sum);

            //cout << v << ' ' << dp[v] << '\n';
        }
        for (int i = 1; i <= n; i++)
            cout << dp[i] << ' ';
        cout << '\n';
    }
}

