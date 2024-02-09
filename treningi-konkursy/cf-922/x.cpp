#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n;
ll a[MAXN];
bool solve (ll limit) {
    ll act = 0;
    ll blocked = 0;
    for (int i = 1; i <= n; i++) {
        if (act + a[i] > limit) {
            blocked += a[i];
            act = 0;
        }
        else {
            act += a[i];
        }
    }
    if (blocked <= limit)
        return 1;
    else
        return 0;
}
ll binSearch(ll l, ll r) {
    if (l == r)
        return l;
    ll mid = (l+r)/2;
    if (solve(mid)) {
        return binSearch(l, mid);
    }
    else {
        return binSearch(mid+1, r);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        cout << binSearch(1, 1e18) << '\n';

    }
}