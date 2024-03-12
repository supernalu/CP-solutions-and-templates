#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
constexpr ll MOD = 998244353;
int t, n;
vector<int> adj[MAXN];
ll dp[MAXN];
//ll subtree[MAXN];
bool done[MAXN];
void dfsDP(int v, ll &res) {
    done[v] = 1;
    dp[v] = 1;
    //subtree[v] = 1;
    //ll tmp = 1;
    for (auto u : adj[v]) {
        if (done[u])
            continue;
        dfsDP(u, res);
        dp[v] = (dp[v]*dp[u])%MOD;
        //subtree[v] += subtree[u];
        res = (res+dp[u]-1)%MOD;
    }
    if (!adj[v].empty()) {
        dp[v] = (dp[v]+1)%MOD;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i < n; i++) {
            dp[i] = 0;
            done[i] = 0;
            //subtree[i] = 0;
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        done[n] = 0;
        dp[n] = 0;
        //subtree[n] = 0;
        ll res = 0;
        dfsDP(1, res);
        res = (res+dp[1])%MOD;
        cout << res << '\n';
    }
}