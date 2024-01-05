#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj { {}, {2, 3}, {1, 4}, {2}, {1, 3} };

int main() {
    vector<bool> vis(adj.size(), false);

    for (int i = 1; i < adj.size(); ++i) {

        auto dfs = [&](int v, auto&& dfs) -> void {
            cout << v << ' ';
            vis[v] = true;
            for (auto u : adj[v]) {
                if (!vis[u]) {
                    dfs(u, dfs);
                }
            }
        };

        if (!vis[i]) {
            dfs(i, dfs);
        }
    }
}