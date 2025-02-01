#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN =  110;
constexpr int INF = 1e9 + 10;
//Edmonds-Karp
int n;
int capacity[MAXN][MAXN];
int parent[MAXN];
int bfs(int s, int t) {
    for (int i = 1; i <= n; i++)
        parent[i] = -1;
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});
    while(!q.empty()) {
        int v = q.front().first, flow = q.front().second;
        q.pop();
        for (int u = 1; u <= n; u++) {
            if (capacity[v][u] == 0 || parent[u] != -1)
                continue;
            parent[u] = v;
            int nFlow = min(flow, capacity[v][u]);
            if (u == t)
                return nFlow;
            q.push({u, nFlow});
        }
    }
    return 0;
}
int maxFlow(int s, int t) {
    int flow = 0;
    int nFlow;
    while (nFlow = bfs(s, t)) {
        flow += nFlow;
        int act = t;
        while (act != s) {
            int prev = parent[act];
            capacity[prev][act] -= nFlow;
            capacity[act][prev] += nFlow;
            act = prev;
        }
    }
    return flow;
}
