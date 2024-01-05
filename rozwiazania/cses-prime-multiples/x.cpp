#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, primes[30];
int k;
vector<bool> mask (int a, int k) {
    vector<bool> res;
    for (int i = k-1; i >= 0 ; i--) {
        if (a >= (1 << i)) {
            res.push_back(1);
            a -= (1 << i);  
        }
        else
            res.push_back(0);
    }
    return res;
}
ll inclusionExclusion (ll n, ll primes[], int k) {
    ll res = n;
    for (int i = 0; i < (1 << k); i++) {
        vector<bool> tmp = mask(i, k); 
        int il = 0;
        ll num = 1;
        for (int j = 0; j < k; j++) {
            if (!tmp[j])
                continue;
            num *= primes[j];
            il = (il+1)%2;
        }
        if (il) 
            res += n/num;
        else
            res -= n/num;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> primes[i];
    cout << inclusionExclusion(n, primes, k);
}