#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 19;
constexpr ll INF = 1e18 + 10;
int n, q, a[LEAVES];
vector<ll> L(2*LEAVES), R(2*LEAVES), RangeSum(2*LEAVES);
void debug() {
    int pow = 1;
    for (int i = 1; i < 2*LEAVES; i++) {
        cout << RangeSum[i] << ' ';
        
        if (i == 2*pow-1) {
            cout << "\n";
            pow *= 2;
        }
    }
}
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
tuple<char, int, int> queries[LEAVES];
map<int, int> scale;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    cin >> n >> q;
    set<int> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val.insert(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        char d; int b, c; cin >> d >> b >> c;
        val.insert(c);
        if (d == '?')
            val.insert(b);
        queries[i] = {d, b, c};
    }
    for (int i = 1; !val.empty(); i++) {
        int tmp = *(val.begin());
        scale[tmp] = i;
        //cout << i << '|' << tmp << '\n';
        val.erase(tmp);
    }
    for (int i = 1; i <= n; i++) {
        //cout << scale[a[i]] << ' ';
        update(scale[a[i]], 1, 1);
    }
    //debug();
    for (int i = 1; i <= q; i++) {
        char d; int b, c; 
        d = get<0>(queries[i]); b = get<1>(queries[i]); c = get<2>(queries[i]);
        if (d == '?') 
            cout << rangeQuery(scale[b], scale[c], 1) << '\n';
        else {
            update(scale[a[b]], -1, 1);
            a[b] = c;
            update(scale[a[b]], 1, 1);
        }
    }
}