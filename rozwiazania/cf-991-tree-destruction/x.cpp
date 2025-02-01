#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t; 
int n;
vector<int> adj[MAXN];
vector<bool> vis(MAXN);
int dp[MAXN][3]; //dp[][0] = 1; dp[][1] - sciezka idzie tylko w dol; dp[][2] - sciezka zakreca
void init() {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        adj[i].clear();
    
    }
}
void dfs(int v) {
    vis[v] = 1;
    dp[v][0] = 1;
    dp[v][1] = adj[v].size()-2;
    dp[v][2] = adj[v].size()-3;
    int maxi1 = 0, maxi2 = 0;
    for (auto u : adj[v]) {
        if (vis[u])
            continue;
        dfs(u);
        if(max(dp[u][0], dp[u][1]) >= maxi1) {
            maxi2 = maxi1;
            maxi1 = max(dp[u][0], dp[u][1]);
        }
        else if (max(dp[u][0], dp[u][1]) > maxi2)
            maxi2 = max(dp[u][0], dp[u][1]);
    }
    dp[v][1] += maxi1;
    dp[v][2] += (maxi1+maxi2);
    dp[v][1] = max({0, dp[v][1], (int)adj[v].size()-1});
    dp[v][2] = max({0, dp[v][2], dp[v][1]});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n; init();

        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        adj[1].push_back(0);
        if (n == 2) {
            cout << "1\n";
            continue;
        }
        dfs(1);
        int res = dp[1][2];
        for (int i = 2; i <= n; i++) { 
            //cout << dp[i][2] << '\n';
            res = max(res, dp[i][2]+1);
        }
        cout << res << '\n';
            


    }
}