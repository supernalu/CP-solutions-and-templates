#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
constexpr long long MOD = 998244353;
typedef long long ll;
int n, k;
long long a[MAXN];
long long dp[MAXN][20];
ll factorial[20];
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
    cin >> n >> k; 
    for (int i = 1; i < 11; i++)
        dp[0][i] = 0;
    for (int i )

}