//!!wrong
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
int t, n, m;
vector<int> adj[MAXN];
int dist[MAXN];
int ile[MAXN];
queue<int> st;
void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
        ile[i] = 0;
    }
    while (!st.empty()) {
        q.push(st.front());
        dist[st.front()] = 0;
        ile[0]++;
        st.pop();
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (dist[u] != -1)
                continue;
            dist[u] = dist[v]+1;
            ile[dist[u]]++;
            q.push(u); 
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            adj[i].clear();
        for (int i = 1; i <= m; i++) {
            int a, b; cin >> a >> b; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        st.push(1);
        bfs();
        for (int i = 1; i <= n; i++) 
            if (ile[dist[i]] == 1) 
                st.push(i);
        bfs();
        int q; cin >> q;
        while (q--) {
            int a; cin >> a;
            cout << dist[a] << ' ';
        }
        cout << '\n';
    }
}