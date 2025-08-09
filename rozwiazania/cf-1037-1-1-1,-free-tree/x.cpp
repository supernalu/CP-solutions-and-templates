#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
constexpr int MAXSQ = 200;
int t, n, q, sq;
vector<pair<int, int>>  adj[MAXN];
int a[MAXN];
int id[MAXN];
int m;
int biggest[MAXSQ];
unsigned int colorSum[MAXSQ][MAXN];
int adjBig[MAXSQ][MAXN];

long long res;
void init() {
    m = 0;
    for (int i = 1; i <= n; i++) {
        id[i] = 0;
        if (adj[i].size() > sq) {
            m++;
            biggest[m] = i;
            id[i] = m;
            for (int j = 1; j <= n; j++) {
                colorSum[m][j] = 0;
                adjBig[m][j] = 0;
            }
            for (auto [u, c] : adj[i]) {
                adjBig[m][u] = c;
                colorSum[m][a[u]] += c;
            }
        }
    }
    res = 0;
    for (int i = 1; i <= n; i++) {
        for (auto [u, c] : adj[i]) {
            if (a[i] != a[u])
                res += c;
        }
    }
    res/=2;

}
void update(int v, int lastC, int newC) {
    for (int i = 1; i <= m; i++) {
        if (adjBig[i][v]) {
            colorSum[i][lastC] -= adjBig[i][v];
            colorSum[i][newC] += adjBig[i][v];
        }
    }
}
/*
void debug() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cout << colorSum[i][j] << ' ';
        }
        cout << '\n';
    }
}
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        sq = 0;
        while (sq*sq<n)
            sq++;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            id[i] = i;
            int v, u; long long c; cin >> v >> u >> c;
            adj[v].push_back({u, c});
            adj[u].push_back({v, c});
        }
        init();  
        while (q--) {
            int v; long long x; cin >> v >> x;
            if (a[v] == x) {
                cout << res << '\n';
                continue;
            }
            update(v, a[v], x);
            if (adj[v].size() <= sq) {
                long long minus = 0;
                long long plus = 0;
                for (auto [u, c] : adj[v]) {
                    if (a[u] == a[v]) {
                        plus+=c;
                    }
                    else if (a[u] == x) {
                        minus+=c;
                    }
                }
                res += plus-minus;
            }
            else {
                res += colorSum[id[v]][a[v]];
                res -= colorSum[id[v]][x];
            }
            //debug();
            a[v] = x;
            cout << res << '\n';
        }
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
    }
}