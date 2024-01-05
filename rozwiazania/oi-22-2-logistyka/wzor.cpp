#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int LEAVES = 1 << 2;
constexpr ll INF = 1e18 + 10;
int n, q;
vector<ll> L(2*LEAVES), R(2*LEAVES), RangeSum(2*LEAVES), lazySum(2*LEAVES), RangeAmount(2*LEAVES), lazyAmount(2*LEAVES);
ll maxVal[LEAVES], act[LEAVES];
void debugA() {
    int pow = 1;
    for (int i = 1; i < 2*LEAVES; i++) {
        cout << RangeAmount[i] << '|' << lazyAmount[i] << ' ';
        
        if (i == 2*pow-1) {
            cout << "\n";
            pow *= 2;
        }
    }
}
void debugS() {
    int pow = 1;
    for (int i = 1; i < 2*LEAVES; i++) {
        cout << RangeSum[i] << '|' << lazySum[i] << ' ';
        
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
void LazyPropagation(int v) {
    if (lazyAmount[v] == 0 && lazySum[v] == 0)
        return;
    if (v < LEAVES) {
        lazySum[2*v] += lazySum[v];
        lazySum[2*v + 1] += lazySum[v];
        lazyAmount[2*v] += lazyAmount[v];
        lazyAmount[2*v + 1] += lazyAmount[v];
    }
    RangeSum[v] += lazySum[v];
    RangeAmount[v] += lazyAmount[v];
    lazySum[v] = 0;
    lazyAmount[v] = 0;
}
void RangeUpdate(int maxi, int val, int v, bool add) {
    LazyPropagation(v);
    if (maxi < maxVal[L[v]]) 
        return;
    if (maxVal[R[v]] <= maxi) {
        lazySum[v] += val;
        if (add)
            lazyAmount[v]++;
        else 
            lazyAmount[v]--;
        LazyPropagation(v);
        return;
    }
    RangeUpdate(maxi, val, 2*v, add); RangeUpdate(maxi, val, 2*v+1, add);    
    
} 
pair<ll, ll> Query(int k, int v) {
    LazyPropagation(v);
    if (k < L[v] || R[v] < k) 
        return {0, 0};
    if (k == L[v] && R[v] == k) 
        return {RangeSum[v], RangeAmount[v]};
    pair<ll, ll> child1 = Query(k, 2*v), child2 = Query(k, 2*v+1);
    return {child1.first + child2.first, child1.second + child2.second};
}
tuple<char, int, int> queries[LEAVES];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); init();
    cin >> n >> q; 
    set<ll> tmp;
    for (int i = 1; i <= q; i++) {
        char a; int b, c; cin >> a >> b >> c;
        queries[i] = {a, b, c};
        if (a == 'Z')
            tmp.insert(c);
    }
    maxVal[0] = 0;
    for (int i = 1; i <= n; i++) {
        RangeUpdate(0, 0, 1, 1);
    }
    debugA();
            debugS();
    int j = 1;
    for (; !tmp.empty(); j++) {
        ll ttmp = *(tmp.begin());
        maxVal[j] = ttmp;
        tmp.erase(tmp.begin());
        cout << maxVal[j] << ' ';
    }
    for (int i = j; i < LEAVES; i++)
        maxVal[i] = 1e14;
    ll sum = 0;
    for (int i = 1; i <= q; i++) {
        char a; int b, c; 
        a = get<0>(queries[i]); b = get<1>(queries[i]); c = get<2>(queries[i]);
        if (a == 'U') {
            ll tmp = act[b];
            sum -= tmp;
            RangeUpdate(tmp, -tmp, 1, 0);
            debugA();
            debugS();

            act[b] = c;
            tmp = act[b];
            sum += tmp;
            RangeUpdate(tmp, tmp, 1, 1);
            debugA();
            debugS();
        }  
        else {
            pair<ll, ll> tmp = Query(c, 1);
            ll res = sum - tmp.first + c*tmp.second;
            if (res >= b*c)
                cout << "TAK\n";
            else
                cout << "NIE\n";
        }
    }
}