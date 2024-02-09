
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
vector<ll> getDividors(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i) continue;
        res.push_back(i); 
        if (n/i != i) res.push_back(n/i);
    }
    return res;
}
ll numberOfDividors(ll n) {
    ll res = 0;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i) continue;
        res++; 
        if (n/i != i) res++;
    }
    return res;
}
void getExponents(const int maxi, vector<int>tab[]) {
    tab[1].push_back(0);
    bool done[maxi+1];
    for (int i = 1; i <= maxi; i++) done[i] = 0;
    for (int i = 2; i <= maxi; i++)
    {
        if (done[i]) continue;
        tab[i].push_back(1); done[i] = 1;
        for (int j = 2*i; j <= maxi; j += i) {
            int tmp = j, res = 0;
            done[j] = 1;
            while (tmp%i == 0) {
                res++; tmp /= i;
            }
            tab[j].push_back(res);
        }
    }
}
void getPrimeDividors(const int maxi, vector<int>tab[]) { 
    tab[1].push_back(1);
    bool done[maxi+1];
    for (int i = 1; i <= maxi; i++) done[i] = 0;
    for (int i = 2; i <= maxi; i++)
    {
        if (done[i]) continue;
        tab[i].push_back(i); done[i] = 1;
        for (int j = 2*i; j <= maxi; j += i) {
            done[j] = 1;
            tab[j].push_back(i);
        }
    }
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
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll xx, yy;
    ll res = gcd(b, a % b, xx, yy);
    x = yy;
    y = xx - yy * (a / b);
    return res;
}
