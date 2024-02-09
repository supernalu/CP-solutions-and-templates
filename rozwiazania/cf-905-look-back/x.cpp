#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5 + 10;
int t, n;
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ll res = 0, last = 0;
        for (int i = 1; i < n; i++) {
            ll maxi = max(a[i], a[i+1]), mini = min(a[i], a[i+1]);
            ll stosunek = (maxi+mini-1)/mini;
            ll tmp = 1, logg = 0;
            while (tmp < stosunek) {
                tmp*=2;
                logg++;
            }
            if (a[i+1] > a[i]) 
                logg = last - logg;
            else 
                logg = logg + last;
            cout << max(0ll, logg) << ' ';
            res += max(0ll, logg);
            last = max(0ll, logg);
        }
        cout << res << '\n';
    }
}