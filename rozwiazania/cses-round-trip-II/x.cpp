//!graph is one-way
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5+10;
constexpr int MAXM = 1e6+10;
int t, n, m;
vector<pair<int, int>> adj[MAXN];
bool vis[MAXN], used[MAXM];
int last[MAXN];
vector<vector<int>> res;
void solve(int st) {
    stack<int> tmp;
    tmp.push(st);
    while(!tmp.empty()) {
        int v = tmp.top(); //cout << v << '\n';
        int i = last[v];
        if (vis[v]) {
            res.push_back({});
            tmp.pop();
            int j = res.size()-1;
            res[j].push_back(v);
            while (tmp.top() != v) {
                res[j].push_back(tmp.top());
                vis[tmp.top()] = 0;
                tmp.pop();
            }
        }
        else {
            vis[v] = 1;
        }
        while (i < adj[v].size() && used[adj[v][i].second])
            i++;
        last[v] = i;
        if (i == adj[v].size())
            break;
        used[adj[v][i].second] = 1;
        tmp.push(adj[v][i].first);
    }
    vis[st] = 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cin >> t;
    t = 1;
    while (t--) {
        for (auto u : res)
            u.clear();
        res.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            last[i] = 0;
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            used[i] = 0;
            int a, b; cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        bool poss = 1;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size()%2 == 1) {
                poss = 0;
                break;
            }
        }
        if (!poss) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            for (auto u : adj[i]) {
                if (used[u.second])
                    continue;
                solve(i);
                break;
            }
        }
        cout << res.size() << '\n';
        for (auto i : res) {
            cout << i.size() << ' ';
            for (auto u : i) {
                cout << u << ' ';
            }
            cout << i[0] << '\n';
        }
    }
}