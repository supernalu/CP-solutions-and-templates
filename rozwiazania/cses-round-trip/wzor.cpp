#include <bits/stdc++.h>
 
//!Do poprawy!
 
using namespace std;
 
constexpr int MAXN = 1e5 + 5;
 
int n, m;
int a, b;
 
vector <int> adj[MAXN];
bool vis[MAXN];
int parent[MAXN];
int dist[MAXN];
bool is_good = false;
int wh;
pair <int, int> res;
int dl;
 
void dfs(int v)
{
    for (auto u: adj[v])
    {
        if (vis[u])
        {
            if (u != parent[v])
            {
                if (dist[v] - dist[u] + 2 >= 4)
                {
                    dl = dist[v] - dist[u] + 2;
                    is_good = true;
                    res.first = u;
                    res.second = v;
 
                }
            }
 
            continue;
        }
            dist[u] = dist[v] + 1;
            parent[u] = v;
            vis[u] = true;
            dfs(u);                       
    }
    
    
}
 
int main()
{
    cin >> n >> m;
 
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            parent[i] = i;
            vis[i] = 1;
            dist[i] = 0;
            dfs(i);
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << ' ';
    }
    */
    if (!is_good)
        cout << "IMPOSSIBLE";
    else 
    {
        cout << dl << endl;
        cout << res.first << ' ';
        int pom = res.second;
        while (pom != res.first)
        {
            cout << pom << ' ';
            pom = parent[pom];
        }
        cout << res.first;
    }
 
}