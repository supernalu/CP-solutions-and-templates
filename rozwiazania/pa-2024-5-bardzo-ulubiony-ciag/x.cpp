#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 500;
typedef long long ll;
int n;
ll a[MAXN];
ll pref[MAXN];
ll solve(ll target) {
    cout << target << '\n';
    map<ll, ll> m;
    ll res = 0;
    m[0] = 1;
    for (int i = 1; i <= n; i++) {
        m[pref[i]] = 0;
        m[pref[i]-target] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << pref[i] << ' ' << m[pref[i]-target] << '\n';
        res += m[pref[i]-target];
        m[pref[i]]++;
    }
    for (auto i : m)
        cout << i.first << ' ' << i.second << ", ";
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i-1]+a[i];
    }
    ll res = 0;
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int k = j+1; k <= n; k++) {
                if (a[i]+a[j]+a[k] == 0)
                    res++;
            }
        }
    }
    */
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            ll tmp = -(a[i]+a[j]);
            res+=solve(tmp);
        }
    }
    cout << res << ' ';
}