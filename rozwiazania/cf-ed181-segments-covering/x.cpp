#include <bits/stdc++.h>
using namespace std;
constexpr int LEAVES = 1 << 19;
typedef long long ll;
constexpr ll MOD=998244353;
int t, n, m;
int l[LEAVES], r[LEAVES], id[LEAVES];
ll p[LEAVES], q[LEAVES];
ll val[LEAVES], valInv[LEAVES];
long long dp[LEAVES];
vector<ll> L(2*LEAVES), R(2*LEAVES), RangeProduct(2*LEAVES);
void init() {
    for (int i = LEAVES; i < 2*LEAVES; i++){
        L[i] = i-LEAVES;
        R[i] = i-LEAVES;
        RangeProduct[i] = 1;
    }
    for (int i = LEAVES-1; i > 0; i--) {
        L[i] = L[2*i];
        R[i] = R[2*i+1];
        RangeProduct[i] = 1;
    }
}
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
void update(int k, int val, int v) {
    if (k < L[v] || R[v] < k) 
        return;
    RangeProduct[v] *= val;
    RangeProduct[v] %= MOD;
    if (L[v] == R[v]) 
        return;
    update(k, val, 2*v); update(k, val, 2*v+1);    
} 
ll rangeQuery(int l, int r, int v) {
    if (r < L[v] || R[v] < l) 
        return 1;
    if (l <= L[v] && R[v] <= r) 
        return RangeProduct[v]%MOD;
    return (rangeQuery(l, r, 2*v)*rangeQuery(l, r, 2*v+1)+MOD)%MOD;
}
bool cmp(int a, int b) {
    return (r[a] < r[b]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); init();
    t = 1;
    while (t--) {
        cin >> m >> n;
        for (int i = 1; i <= m; i++) {
            cin >> l[i] >> r[i] >> p[i] >> q[i];
            id[i] = i;
            val[i] = p[i]*fastExp(q[i], MOD-2, MOD)%MOD;
            valInv[i] = ((q[i]-p[i])*fastExp(q[i], MOD-2, MOD))%MOD;
            //cout << valInv[i] << ' ';
            update(r[i], valInv[i], 1);
        }
        sort(id+1, id+m+1, cmp);
        int it = 1;
        
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            while (it <= m && r[id[it]] == i) {
                //cout << i << ' ' << it << '\n';
                ll tmp = (dp[l[id[it]]-1]*rangeQuery(l[id[it]], r[id[it]], 1))%MOD;
                //cout << rangeQuery(l[id[it]], r[id[it]], 1) << ' ';
                tmp = (tmp*fastExp(valInv[id[it]], MOD-2, MOD))%MOD;
                //cout << tmp << ' ';
                tmp = (tmp*val[id[it]])%MOD;
                //cout << tmp << '\n';
                dp[i] = (dp[i]+tmp)%MOD;
                it++;
            }
        }
        cout << dp[n] << '\n';

        //for (int i = 1; i <= m; i++) {
            //update(r[i], fastExp(valInv[i], MOD-2, MOD), 1);
        //}
    }
}