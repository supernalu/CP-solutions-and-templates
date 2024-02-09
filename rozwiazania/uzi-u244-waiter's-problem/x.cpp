#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 1e5+10;
int t;
ll n, a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        sort(a+1, a+n+1);
        ll res = 0, minus = 0, suf = 0;
        for (ll i = 1; i <= n; i++) {
            minus += i-1;
            suf += a[n+1-i];
            res = max(res, suf-minus);
        }
        cout << res << '\n';
    }
}