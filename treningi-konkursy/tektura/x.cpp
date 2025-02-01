#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
constexpr ll INF = 1e18 + 10;
int t;
int n, m, h;
vector<pair<int, ll>> adj[MAXN];
bool isHorse[MAXN];
ll dist[MAXN][2];
ll sum[MAXN];
bool done[MAXN][2];
void dijkstra(int a) {
    priority_queue<tuple<long long, int, bool>, vector<tuple<long long, int, bool>>, greater<tuple<long long, int, bool>>> pq;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < 2; j++)
            dist[i][j] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            done[i][j] = 0;
    dist[a][0] = 0; 
    pq.push({0, a, 0});
 
    while (!pq.empty()) {
        int v = get<1>(pq.top());
        bool horsey = get<2>(pq.top());
        pq.pop();
 
        if (done[v][horsey]) continue;
 
        done[v][horsey] = true;
        if (horsey == 0 && isHorse[v] == 1) {
            if (dist[v][1] > dist[v][0])  {         
                dist[v][1] = dist[v][0];
                pq.push({dist[v][1], v, 1});
            }
        }
        for (auto u: adj[v]) {
            int ch = u.second;
            if (horsey)
                ch /= 2;
            if (dist[u.first][horsey] > dist[v][horsey] + ch)  {         
                dist[u.first][horsey] = dist[v][horsey] + ch;
                pq.push({dist[u.first][horsey], u.first, horsey});
            } 

        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> h;
        for (int i = 1; i <= n; i++)
            isHorse[i] = 0;
        for (int i = 1; i <= h; i++) {
            int a; cin >> a;
            isHorse[a] = 1;
        }
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        dijkstra(1);
        for (int i = 1; i <= n; i++) {
            sum[i] = min(dist[i][0], dist[i][1]);
        }
        dijkstra(n);
        ll res = INF;
        for (int i = 1; i <= n; i++) {
            sum[i] = max(sum[i], min(dist[i][0], dist[i][1]));
            res = min(res, sum[i]);
        }
        if (res == INF)
            cout << "-1\n";
        else
            cout << res << '\n';
    }
}