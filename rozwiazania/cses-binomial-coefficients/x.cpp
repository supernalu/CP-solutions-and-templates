#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n; 
char s[1000010];
ll factorial[1000010];
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
void getFactorial(int maxi, ll MOD) {
    factorial[0] = 1;
    for (int i = 1; i <= maxi; i++)
        factorial[i] = (factorial[i-1]*i)%MOD;
}
ll BinomialCoefficent(ll a, ll b, ll MOD) {
    // a choose b
    ll tmp1 = factorial[a], tmp2 = factorial[b], tmp3 = factorial[a-b], res = 1;
    res = (res*tmp1)%MOD; res = (res*fastExp(tmp2, MOD-2, MOD))%MOD; res = (res*fastExp(tmp3, MOD-2, MOD))%MOD; 
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getFactorial(1000000, MODULO);
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        cout << BinomialCoefficent(a, b, MODULO) << '\n';
    }
    
}