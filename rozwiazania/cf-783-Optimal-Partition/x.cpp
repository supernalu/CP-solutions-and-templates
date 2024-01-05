//*range-range type
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 19;
constexpr ll INF = 2e14 + 10000;
int t, n, q, id[LEAVES], idRev[LEAVES];
vector<int> L(2*LEAVES), R(2*LEAVES); 
vector<ll> RangeMaxi(2*LEAVES), lazy(2*LEAVES, 0);
ll dp[MAXN], a[LEAVES], suf[LEAVES];
bool cmp(int v, int u) {
    if (suf[v] == suf[u])
        return v < u;
    return suf[v] < suf[u];
}
void init() {
    for (int i = LEAVES; i < 2*LEAVES; i++){
        L[i] = i-LEAVES;
        R[i] = i-LEAVES;
        RangeMaxi[i] = -INF;
    }
    for (int i = LEAVES-1; i > 0; i--) {
        L[i] = L[2*i];
        R[i] = R[2*i+1];
        RangeMaxi[i] = -INF; 
    }
}
void LazyPropagation(int v) {
    if (lazy[v] == 0)
        return;
    if (v < LEAVES) {
        lazy[2*v] += lazy[v];
        lazy[2*v + 1] += lazy[v];
    }
    RangeMaxi[v] += lazy[v];
    lazy[v] = 0;
}
void RangeUpdate(int l, int r, ll val, int v) {
    LazyPropagation(v);
    if (r < L[v] || R[v] < l) 
        return;
    if (l <= L[v] && R[v] <= r) {
        lazy[v] += val;
        LazyPropagation(v);
        return;
    }
    RangeUpdate(l, r, val, 2*v); RangeUpdate(l, r, val, 2*v+1);   
    RangeMaxi[v] = max(RangeMaxi[2*v], RangeMaxi[2*v+1]); 
} 
ll RangeQuery(int l, int r, int v) { 
    LazyPropagation(v);
    if (r < L[v] || R[v] < l) 
        return -INF;
    if (l <= L[v] && R[v] <= r) 
        return RangeMaxi[v];
    return max(RangeQuery(l, r, 2*v), RangeQuery(l, r, 2*v+1));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        init();
        cin >> n; 
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        suf[n+1] = 0;
        for (int i = n; i > 0; i--) {
            suf[i] = suf[i+1] + a[i];
            id[i] = i;
        }
        sort(id+1, id+n+1);
        for (int i = 1; i <= n; i++) {
            idRev[id[i]] = i;
        }
        dp[0] = 0;
        if (a[1] > 0)
            
    }
}