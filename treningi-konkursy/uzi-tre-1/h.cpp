#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n;
long long u[MAXN], z[MAXN];
vector<int> adj[MAXN];
long long dp[MAXN];
bool vis[MAXN];
void dfs(int k) {
    vis[k] = 1;
    dp[k] = z[k];
    long long better = u[k];
    for (auto v : adj[k]) {
        if (vis[v] == 0) 
            dfs(v);
        better += dp[v];
    }
    dp[k] = min(dp[k], better);
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> u[i] >> z[i] >> r;
        for (int j = 1; j <=r; j++) {
            int a;
            cin >> a;
            adj[i].push_back(a);
        }
    }
    dfs(1);
    cout << dp[1];
}