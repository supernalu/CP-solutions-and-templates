#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n, m, q;
set<pair<int, long long>> adj[MAXN];
int colorr[MAXN];
long long odl[MAXN];
int parent[MAXN];
void dfs(int v, int k, long long maxOdl) {
    if (odl[v] > maxOdl)
        return;
    colorr[v] = k;
    for (auto u : adj[v]) {
        if (u.first == parent[v])
            continue;
        odl[u.first] = odl[v] + u.second;
        dfs(u.first, k, maxOdl);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long d; cin >> a >> b >> d;
        adj[a].insert({b, d});
        adj[b].insert({a, d});
    }
    for (int i = 0; i < q; i++) {
        //cout << i << ' ';
        int type; cin >> type;
        switch (type) {
            int a, b; 
            long long d;
            case 1:
                cin >> a >> b >> d;
                adj[a].insert({b, d});
                adj[b].insert({a, d});
                break;
            case 2:
                cin >> a >> b;
                d = (*(adj[a].lower_bound({b, 0}))).second;
                adj[a].erase({b, d});
                adj[b].erase({a, d});
                break;
            case 3:
                int start, maxOdl, color; cin >> start >> maxOdl >> color;
                parent[start] = 0;
                odl[start] = 0;
                dfs(start, color, maxOdl);
                break;
            case 4: 
                int v; cin >> v;
                cout << colorr[v] << '\n';
                break;
        }
    }
}