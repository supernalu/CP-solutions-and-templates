#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n;
vector<int> adj[MAXN];
vector<bool> vis(MAXN, 0);
vector<int> odl(MAXN, 0);
int res[MAXN];
void dfs(int v) {
    for (auto u : adj[v]) {
        if (vis[u])
            continue;
        vis[u] = 1;
        odl[u] = odl[v]+1;
        dfs(u);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    odl[1] = 0;
    dfs(1);
    int v1 = 1;
    for (int i = 2; i <= n; i++) {
        if (odl[i] > odl[v1])
            v1 = i;
    }
    odl.assign(MAXN, 0);
    vis.assign(MAXN, 0);
    vis[v1] = 1;
    dfs(v1);
    for (int i = 1; i <= n; i++)
        res[i] = odl[i];
    int v2 = 1;
    for (int i = 2; i <= n; i++) {
        if (odl[i] > odl[v2])
            v2 = i;
    }
    odl.assign(MAXN, 0);
    vis.assign(MAXN, 0);
    vis[v2] = 1;
    dfs(v2);
    for (int i = 1; i <= n; i++) {
        res[i] = max(res[i], odl[i]);
        cout << res[i] << ' ';
    }
    
}