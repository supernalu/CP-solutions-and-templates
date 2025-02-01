//! PROBLEMY: nie wykrywa cyklu typu 1 - 2 - 1, bo 1 jest parentem 2
//* ROZWIĄZANIE: napisać solve, który łaczy spójne składowe i zlicza ilość wierzchołków i krawędzi.
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 20;
int n, q;
multiset<int> adj[MAXN];
int answer[MAXN];
vector<bool> vis;
vector<int> toChange;
vector<int> parent;
int ileV, ileM;
void dfs(int v) {
    toChange.push_back(v);
    ileV++;
    ileM += adj[v].size();
    vis[v] = 1;
    int odp = 0; 
    for (auto u : adj[v]) {
        if (vis[u]) { 
            continue;
        }
        parent[u] = v;
        dfs(u);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    while (q--) {
        char type; cin >> type;
        if (type == '+') {
            int a, b; cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
            answer[a] = max(answer[a], 1);
            answer[b] = max(answer[b], 1);
            vis.assign(n+10, 0);
            parent.assign(n+10, 0);
            ileV = 0;
            ileM = 0;
            toChange.clear();
            dfs(a);
            ileM /= 2;
            if (ileM < ileV)
                continue;
            for (auto i : toChange)
                answer[i] = 2;
            //cout << '\n';
        }
        else if (type == '-') {
            int query; cin >> query;
            for (auto i = adj[query].begin(); i != adj[query].end(); i++) {
                if (*i == query)
                    continue;
                adj[*i].erase(query);
                if (adj[*i].empty() && answer[*i] != 2 && adj[query].size() == 1)
                    answer[*i] = 0;
            }
            answer[query] = 0;
            adj[query].clear();
        }
        else {
            int query; cin >> query;
            if (answer[query] == 2) {
                cout << 1;
            }
            else if (answer[query] == 1) {
                cout << '?';
            } 
            else {
                cout << 0;
            }
        }
    }
}