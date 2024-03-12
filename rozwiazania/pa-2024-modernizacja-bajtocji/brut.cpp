//! PROBLEMY: nie wykrywa cyklu typu 1 - 2 - 1, bo 1 jest parentem 2
//* ROZWIĄZANIE: napisać solve, który łaczy spójne składowe i zlicza ilość wierzchołków i krawędzi.
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 20;
int n, q;
multiset<int> adj[MAXN];
int answer[MAXN];
vector<bool> vis;
vector<int> startPoints;
vector<int> parent;
int dfs(int v) {
    //cout << v << ' ';
    vis[v] = 1;
    int odp = 0; 
    for (auto u : adj[v]) {
        if (vis[u]) {
            if (parent[v] == u)
                continue;
            startPoints.push_back(u);
            answer[u] = 2;
            continue;
        }
        parent[u] = v;
        dfs(u);
    }
}
void bfs() {
    queue<int> q;
    for (auto i : startPoints) {
        q.push(i);
        answer[i] = 2;

    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (answer[u] == 2)
                continue;
            answer[u] = 2;
            q.push(u);
        }
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
            dfs(a);
            bfs();
            //cout << '\n';
        }
        else if (type == '-') {
            int query; cin >> query;
            for (auto i = adj[query].begin(); i != adj[query].end(); i++) {
                adj[*i].erase(query);
                if (adj[*i].empty() && answer[*i] != 2)
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