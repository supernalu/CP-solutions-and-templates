#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll check(ll k, ll i, ll n) {
    ll res = 0;
    ll third = n-i-k;
    if (third%i == 0 && third%k == 0 && third > i)
        res = 1;
    return res;
}
ll solve(ll k, ll n) {
    ll res = 0;
    for (int i = 2*k; i*i <= n; i+=k) {
       if (n%i)
            continue;
        cout << i << ' ';
        res += check(k, i, n);
        if (n != i*i && (n/i)%k == 0)
            res += check(k, n/i, n);
    }
    cout << '\n';
    return res;
}
int main() {
    ll n; cin >> n;
    ll res = 0;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i)
            continue;
        cout << i << '\n';
        res += solve(i, n-i);
        if (n != i*i)
            res += solve(n/i, n-n/i);
    }
    cout << res << '\n';
}