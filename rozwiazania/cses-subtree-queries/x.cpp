#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 19;
int n, q;
vector<int> adj[LEAVES];
ll nodeVal[LEAVES];
int flatTree[LEAVES];
int first[LEAVES];
int last[LEAVES];
vector<ll> L(2*LEAVES), R(2*LEAVES), RangeSum(2*LEAVES);
vector<bool> vis(LEAVES);
int act = 1;
void flatten(int v) {
    if (vis[v])
        return;
    flatTree[act] = v;
    first[v] = act;
    vis[v] = 1;
    act++;
    for (auto u : adj[v]) {
        flatten(u);
    }
    flatTree[act] = v;
    last[v] = act;
    act++;
}
void init() {
    for (int i = LEAVES; i < 2*LEAVES; i++) {
        L[i] = i-LEAVES;
        R[i] = i-LEAVES;
        RangeSum[i] = nodeVal[flatTree[i-LEAVES]];
    }
    for (int i = LEAVES-1; i > 0; i--) {
        L[i] = L[2*i];
        R[i] = R[2*i+1];
        RangeSum[i] = RangeSum[2*i]+RangeSum[2*i+1];
    }
}
void update(int k, int change, int v) {
    if (k < L[v] || R[v] < k)
        return;
    RangeSum[v] += change;
    if (L[v] == R[v])
        return;
    update(k, change, 2*v); update(k, change, 2*v+1);
}
ll sum(int l, int r, int v) {
    if (r < L[v] || R[v] < l)
        return 0;
    if (l <= L[v] && R[v] <= r)
        return RangeSum[v];
    return sum(l, r, 2*v)+sum(l, r, 2*v+1);
}
void debug() {
    int act = 2;
    for (int i = 1; i < 2*LEAVES; i++) {
        if (i == act) {
            cout << '\n';
            act *= 2;
        }
        cout << RangeSum[i] << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> nodeVal[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    flatten(1);
    init();
    //for (int i = 1; i <= 2*n; i++)
        //cout << flatTree[i] << ' ';
    //cout << '\n';
    while (q--) {
        //debug();
        int type; cin >> type;
        if (type == 1) {
            int v, change; cin >> v >> change;
            int actChange = change-nodeVal[v];
            nodeVal[v] = change;
            update(first[v], actChange, 1);
            update(last[v], actChange, 1);
        }
        else {
            int v; cin >> v;
            //cout << first[v] << ' ' << last[v] << '\n';
            cout << sum(first[v], last[v], 1)/2 << '\n';
        }
    }
}