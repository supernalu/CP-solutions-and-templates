#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n;
ll m, a[MAXN], c[MAXN], id[MAXN];
bool cmp(ll k, ll g) {
    return a[k] < a[g];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            id[i] = i;
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> c[i]; 
            res = max(res, a[i]*min(c[i], m/a[i]));
        }
        sort(id+1, id+n+1, cmp);
        for (int i = 1; i < n; i++) {
            if (a[id[i]]+1 != a[id[i+1]])
                continue;
            //if (c[id[i]]*a[id[i]]+c[id[i+1]]*a[id[i+1]] <= m)
                //res = max(res, c[id[i]]*a[id[i]]+c[id[i+1]]*a[id[i+1]]);
            long long coins, x = a[id[i]];
            ll k1 = min(c[id[i]], m/x);
            coins = m-k1*x;
            ll k2 = min(c[id[i+1]], coins/(x+1));
            coins = m-(k1*x+k2*(x+1));
            ll r = min({k1, c[id[i+1]]-k2, coins});
            res = max(res, (k1-r)*x+(k2+r)*(x+1));
        }
        cout << res <<'\n';

    }
}