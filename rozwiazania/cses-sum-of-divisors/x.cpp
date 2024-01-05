#include <bits/stdc++.h>
#define ll unsigned long long
constexpr ll MOD = 1e9 + 7;
using namespace std;
ll n;
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
ll sum(ll k) {
    ll res = (k*fastExp(2, MOD-2, MOD))%MOD;
    res = (res*(k+1))%MOD;
    return res;
}
int main() {
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     cin >> n;
     ll last = 0;
     ll res = 0;
    ll i;
     for (i = 1; i*i <= n; i++) {
        //if ((i+1)*(i+1) > n)
        //cout << i << ' ' << n/i << ' ' <<  last << '\n';
        ll tmp = n/i; tmp = (tmp*i)%MOD;
        res = (res+tmp)%MOD;
        if (last == 0) {
            last = n/i;
            continue;
        }
        ll lol = n/i;
        tmp = (sum(last)+MOD-sum(lol))%MOD; 
        tmp = (tmp*(i-1))%MOD;
        //cout << tmp << ' ';
        res = (res+tmp)%MOD;
        last = n/i;
     }
     if (last != i-1) {
        ll tmp = n/i; tmp = (tmp*i)%MOD;
        res = (res+tmp)%MOD;
     }
    
     cout << res << '\n';
}