#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 18;
constexpr ll INF = 1e18 + 10;
int n, q;
vector<ll> L(2*LEAVES), R(2*LEAVES), RangeSum(2*LEAVES), lazy(2*LEAVES);
void init() {
    for (int i = LEAVES; i < 2*LEAVES; i++){
        L[i] = i-LEAVES;
        R[i] = i-LEAVES;
    }
    for (int i = LEAVES-1; i > 0; i--) {
        L[i] = L[2*i];
        R[i] = R[2*i+1];
    }
}
void LazyPropagation(int v) {
    if (lazy[v] == 0)
        return;
    if (v < LEAVES) {
        lazy[2*v] += lazy[v];
        lazy[2*v + 1] += lazy[v];
    }
    RangeSum[v] += lazy[v];
    lazy[v] = 0;
}
void RangeUpdate(int l, int r, int val, int v) {
    LazyPropagation(v);
    if (r < L[v] || R[v] < l) 
        return;
    if (l <= L[v] && R[v] <= r) {
        lazy[v] += val;
        LazyPropagation(v);
        return;
    }
    RangeUpdate(l, r, val, 2*v); RangeUpdate(l, r, val, 2*v+1);    
} 
ll Query(int k, int v) {
    LazyPropagation(v);
    if (k < L[v] || R[v] < k) 
        return 0;
    if (k == L[v] && R[v] == k) 
        return RangeSum[v];
    return Query(k, 2*v) + Query(k, 2*v+1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        RangeUpdate(i, i, a, 1);
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, u; cin >> l >> r >> u;
            RangeUpdate(l, r, u, 1);
        }
        else {
            int k; cin >> k;
            cout << Query(k, 1) << '\n';
        }
    }
}