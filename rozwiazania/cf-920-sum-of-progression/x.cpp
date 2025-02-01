#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 1e5 + 10;
constexpr int SQRTN = 400;
int t, n, q;
ll a[MAXN];
ll sufSum[SQRTN][MAXN], sufRes[SQRTN][MAXN];
void init() {
    for (ll k = 1; k*k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            sufSum[k][i] = 0;
            sufRes[k][i] = 0;
        }
    }
    for (ll k = 1; k*k <= n; k++) {
        for (int st = n; st > n-k; st--) {
            sufRes[k][st] = a[st];
            sufSum[k][st] = a[st];
            for (int i = st-k; i > 0; i-=k) {
                sufSum[k][i] = sufSum[k][i+k] + a[i];
                sufRes[k][i] = sufSum[k][i] + sufRes[k][i+k];
            }
        }
    }
}
ll brutSolve(int s, int d, int k) {
    ll res = 0, move = 1;
    for (int i = s; i <= s + d*(k-1); i+=d) {
        res += a[i]*move;
        move++;
    }
    return res;
}
ll solve(int s, int d, int k) {
    ll res = sufRes[d][s];
    if (s+d*k <= n) {
        res -= (sufRes[d][s+d*k]+(ll)(k)*sufSum[d][s+d*k]);
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        init();
        while (q--) {
            ll s, d, k; cin >> s >> d >> k;
            if (d*d > n) {
                cout << brutSolve(s, d, k) << ' ';
            }
            else {
                cout << solve(s, d, k) << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}