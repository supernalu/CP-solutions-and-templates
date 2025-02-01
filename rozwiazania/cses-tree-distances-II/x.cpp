#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
typedef long long ll;
int n;
vector<int> adj[MAXN];
ll sizeSubtree[MAXN];
ll sum;
ll res[MAXN];
vector<bool> vis(MAXN, 0);
void sumuj(int v, int odl) {
    sum += odl;
    vis[v] = 1;
    sizeSubtree[v] = 1;
    for (auto u : adj[v]) {
        if (vis[u])
            continue;
        sumuj(u, odl+1);
        sizeSubtree[v] += sizeSubtree[u];
    }
    //cout << v << ": " << sizeSubtree[v] << '\n';
}

void dfs(int v, ll act) {
    if (vis[v])
        return;
    vis[v] = 1;
    res[v] = act;
    for (auto u : adj[v]) {
        dfs(u, act -sizeSubtree[u]+n-sizeSubtree[u]);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sum = 0;
    sumuj(1, 0);
    vis.assign(MAXN, 0);
    dfs(1, sum);
    for (int i = 1; i <= n; i++) 
        cout << res[i] << ' ';
}