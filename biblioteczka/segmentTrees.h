//*point-range type

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



//*range-point type

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



//*range-range type
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 19;
constexpr ll INF = 2e14 + 10000;
int n, q;
vector<int> L(2*LEAVES), R(2*LEAVES); 
vector<ll> RangeMaxi(2*LEAVES), lazy(2*LEAVES, 0);
ll act[LEAVES];
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
