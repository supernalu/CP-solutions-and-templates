#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n; 
char s[MAXN];
ll factorial[MAXN];
ll ile[30];
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
void getFactorial(int maxi, ll MOD, ll factorial[]) {
    factorial[0] = 1;
    for (int i = 1; i <= maxi; i++)
        factorial[i] = (factorial[i-1]*i)%MOD;
}
ll BinomialCoefficent(ll a, ll b, ll MOD, ll factorial[]) {
    // a choose b
    ll tmp1 = factorial[a], tmp2 = factorial[b], tmp3 = factorial[a-b], res = 1;
    res = (res*tmp1)%MOD; res = (res*fastExp(tmp2, MOD-2, MOD))%MOD; res = (res*fastExp(tmp3, MOD-2, MOD))%MOD; 
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getFactorial(1000000, MODULO, factorial);
    cin >> s + 1; n = strlen(s+1);
    for (int i = 1; i <= n; i++)
        ile[s[i]-'a']++;
    ll act = n, res = 1;
    for (int i = 1; i < 30; i++) {
        res = (res*BinomialCoefficent(act, ile[i], MODULO, factorial))%MODULO;
        act -= ile[i];
    }
    cout << res << '\n';

    
}