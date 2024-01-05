#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll MODULO = 1e9 + 7;
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        cout << fastExp(a, b, MODULO) << '\n';
    }
}