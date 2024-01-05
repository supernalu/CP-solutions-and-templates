#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e5 + 20;

int n, k;

vector<int> adj[MAXN];

vector<int> vis(MAXN, 0);

int agents[MAXN];

int place[MAXN];

int dp[MAXN];

int res;

int parent[MAXN];

int dist[MAXN];

void dfs(int v, int k)
{
    for (auto u : adj[v])
    {
        if (u == parent[v] || vis[u] != k && vis[u] != 0)
            continue;
        
        dist[u] = dist[v]+1;
        parent[u] = v;

        dfs(u, k);
    }
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> agents[i];
    }

    for (int i = 1; i <= n-1; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    if (n <= 10)
    {
        vector<int>perm;

        for (int i = 1; i <= n; i++)
        {
            perm.push_back(i);
        }

        do
        {

            for (auto i : perm)
            {
                int mini = 1e9 + 10;
                int id = 0;

                for (int i = 1; i <= k; i++)
                {
                    for (int i = 1; i <= n; i++)
                    {
                        parent[i] = 0;
                    }

                    parent[place[i]] = 
                }
            }
        } while(next_permutation(perm.begin(), perm.end()));
    }



}