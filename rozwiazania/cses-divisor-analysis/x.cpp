#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
constexpr ll MODULO = 1e9 + 7;
int n;
ll primes[MAXN], exponents[MAXN];
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
    cin >> n;
    ll numberofDividors = 1, sumOfDividors = 1, numberofDividors2 = 1;
    for (int i = 1; i <= n; i++) {
        cin >> primes[i] >> exponents[i];
        numberofDividors = (numberofDividors*(exponents[i]+1))%MODULO;
        numberofDividors = (numberofDividors*(exponents[i]+1))%(MODULO-1);
        ll tmp = (((fastExp(primes[i], exponents[i]+1, MODULO)+MODULO-1)%MODULO)*fastExp(primes[i]-1, MODULO-2, MODULO))%MODULO;
        sumOfDividors = (sumOfDividors*tmp)%MODULO;
    } cout << numberofDividors << ' '  << sumOfDividors;
}
