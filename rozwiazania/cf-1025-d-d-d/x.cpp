#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
int t, n, m, l;
vector<pair<int, bool>> adj[MAXN][2];
int a[MAXN];

bool vis[MAXN][2];
bool res[MAXN];
int dist[MAXN][2];

void bfs(int st) {
    for (int i = 1; i <= n; i++) {
        vis[i][0] = 0;
        vis[i][1] = 0;
    }
    dist[st][0] = 0;
    vis[st][0] = 1;
    queue<pair<int, int>> q;
    q.push({st, 0});
    while (!q.empty()) {
        int v = q.front().first, parity = q.front().second;
        q.pop();
        for (auto [u, p] : adj[v][parity]) {
            if (vis[u][p])
                continue;
            q.push({u, p});
            vis[u][p] = 1;
            dist[u][p] = dist[v][parity]+1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> l;
        int miniOdd = 2e9;
        int resEven = 0, resOdd = 0;
        for (int i = 1; i <= l; i++) {
            cin >> a[i];
            if (a[i]%2)
                miniOdd = min(miniOdd, a[i]);
            resEven+= a[i];
        }
        if (resEven%2) {
            resOdd = resEven;
            resEven=resOdd-miniOdd;
        }
        else {
            resOdd=resEven-miniOdd;
        }
        //cout << "HERE " << resEven << ' ' << resOdd << '\n';
        for (int i = 1; i <= n; i++) {
            dist[i][0] = 2e9+1;
            dist[i][1] = 2e9+1;
            adj[i][0].clear();
            adj[i][1].clear();
        }

        for (int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b;
            adj[a][0].push_back({b, 1});
            adj[a][1].push_back({b, 0});
            adj[b][0].push_back({a, 1});
            adj[b][1].push_back({a, 0});
        }
        
        bfs(1);
        for (int i = 1; i <= n; i++) {
            //cout << dist[i][0] << ' ' << dist[i][1] << '\n';
            if (dist[i][0] <= resEven || dist[i][1] <= resOdd)
                res[i] = 1;
            else
                res[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (res[i])
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
}