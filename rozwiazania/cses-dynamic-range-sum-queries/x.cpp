#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 18;
constexpr ll INF = 1e18 + 10;
int n, q;
vector<ll> L(2*LEAVES), R(2*LEAVES), RangeSum(2*LEAVES);
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
void update(int k, int val, int v) {
    if (k < L[v] || R[v] < k) 
        return;
    RangeSum[v] += val;
    if (L[v] == R[v]) 
        return;
    update(k, val, 2*v); update(k, val, 2*v+1);    
} 
ll rangeQuery(int l, int r, int v) {
    if (r < L[v] || R[v] < l) 
        return 0;
    if (l <= L[v] && R[v] <= r) 
        return RangeSum[v];
    return rangeQuery(l, r, 2*v)+rangeQuery(l, r, 2*v+1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        update(i, a, 1);
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int k, u, val; cin >> k >> u;
            val = u - RangeSum[LEAVES+k];
            update(k, val, 1);
        }
        else {
            int l, r; cin >> l >> r;
            cout << rangeQuery(l, r, 1) << '\n';
        }
    }
}