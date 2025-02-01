#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN =  110;
constexpr int INF = 1e9 + 10;
//Edmonds-Karp
int n, m;
int a[MAXN], capacity[MAXN][MAXN];
int parent[MAXN];
int numberOfPrimeDividors(int k) {
    int i = 2; 
    int res = 0;
    while (i*i <= k) {
        if (k%i) {
            i++;
            continue;
        }
        while (k%i == 0) {
            k/=i;
            res++;
        }
        i++;
    }
    if (k != 1)
        res++;
    return res;
}
int bfs(int s, int t) {
    for (int i = 0; i <= n+1; i++)
        parent[i] = -1;
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, 0});
    while(!q.empty()) {
        int v = q.front().first, flow = q.front().second;
        //cout << v << ' ' << flow << '\n';
        q.pop();
        for (int u = 0; u <= n+1; u++) {
            //cout << __gcd(capacity[v][u], flow) << ' ';
            if (parent[u] != -1 || __gcd(capacity[v][u], flow) == 1)
                continue;
            parent[u] = v;
            int nFlow = __gcd(flow, capacity[v][u]);
            if (u == t)
                return nFlow;
            q.push({u, nFlow});
        }
    }
    return 1;
}
int maxFlow(int s, int t) {
    int flow = 0;
    int nFlow = bfs(s, t);
    while (numberOfPrimeDividors(nFlow)) {
        //cout << nFlow << ' ';
        flow += numberOfPrimeDividors(nFlow);
        int act = t;
        while (act != s) {
            int prev = parent[act];
            capacity[prev][act] /= nFlow;
            capacity[act][prev] *= nFlow;
            act = prev;
        }
        nFlow = bfs(s, t);
    }
    return flow;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            capacity[i][j] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int v, u; cin >> v >> u;
        if (v%2 == 0)
            swap(v, u);
        capacity[v][u] = __gcd(a[v], a[u]);
        capacity[u][v] = 1;
    }
    for (int i = 1; i <= n; i+=2) {
        capacity[0][i] = a[i];
        capacity[i][0] = 1;
    }
    for (int i = 2; i <= n; i+=2) {
        capacity[i][n+1] = a[i];
        capacity[n+1][i] = 1;
    }
    /*
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= n+1; j++)
            cout << capacity[i][j] << ' ';
        cout << '\n';
    }
    */
    cout << maxFlow(0, n+1);
}