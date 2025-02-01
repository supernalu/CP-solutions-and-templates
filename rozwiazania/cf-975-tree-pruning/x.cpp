#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5+10;
int t, n;
set<int> adj[MAXN];
int ileLvl[MAXN];
int depth[MAXN];
set<pair<int, int>> leafs;
void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        ileLvl[i] = 0;
        depth[i] = 0;
    }
}
void countDepth(int v) {
    for (auto u : adj[v]) {
        if (depth[u] != 0)
            continue;
        depth[u] = depth[v]+1;
        countDepth(u);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n; init();
        for (int i = 1; i < n; i++) {
            int a, b; cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        depth[1] = 1;
        countDepth(1);
        for (int i = 1; i <= n; i++) {
            ileLvl[depth[i]]++; 
            if (adj[i].size() == 1 && i != 1)
                leafs.insert({depth[i], i});
        }
    }
}