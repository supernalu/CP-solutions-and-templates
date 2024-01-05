#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5010;
int n;
vector<int> adj[MAXN];
bool vis[MAXN];
int permu[MAXN];
int act = 1;
void dfs(int v)
{
    
    for (auto u : adj[v])
    {
        if (vis[u])
            continue;
        dfs(u);
        if (permu[v] == 0)
        {
            permu[v] = act;
            act++;
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a; cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs(1);

}