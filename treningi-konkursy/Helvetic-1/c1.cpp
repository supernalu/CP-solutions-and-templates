#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int n, t, s; 
vector<int> adj[MAXN];
int res[MAXN];
int deep[MAXN];
int resPref[2][MAXN];
vector<bool> done(MAXN, 0);
void dfs(int v) {
    bool doneSmth = 0;
    if (deep[v]%2 == 0) {
        res[v] = 0;
        res[v] = 1;
    }
    else {
        res[v] = 1;
        res[v] = 0;
    }
    for (auto u : adj[v]) {
        if (deep[u] != -1)
            continue;
        doneSmth = 1;
        deep[u] = deep[v]+1;
        dfs(u);
        if (deep[v]%2 == 0) {
            res[v] = max(res[u], res[v]);
        }
        else {
            res[v] = min(res[u], res[v]);
        }
    }
    if (!doneSmth) {
        res[v] = deep[v]%2; 
        res[v] = (deep[v]+1)%2;
    }
    
}
void dfs2(int v) {
    done[v] = 1;
    if (res[v] == 1) {
        resPref[1][v] = 1;
        resPref[0][v] = max(resPref[0][v], 0);
    }
    else {
        resPref[1][v] = max(resPref[1][v], 0);
        resPref[0][v] = 1;
    }
    for (auto u : adj[v]) {
        if (done[u]) 
            continue;
        resPref[1][u] = resPref[1][v];
        resPref[0][u] = resPref[0][v];
        dfs2(u);       
    }
    cout << v << ": " << resPref[0][v] << ' ' << resPref[1][v] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.tie(0);
    cin >> n >> t;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        deep[i] = -1;
    }
    deep[1] = 0;
    dfs(1);
    /*
    done[1] = 0;
    if (res[1] == 1) {
        resPref[1][1] = 1;
        resPref[0][1] = 0;
    }
    else {
        resPref[1][1] = 0;
        resPref[0][1] = 1;
    }
    */
    dfs2(1);
    while (t--) {
        int s; cin >> s;
        if (resPref[(deep[s]+1)%2][s] == 1)
            cout << "Ron\n";
        else
            cout << "Hermione\n";
    }
}