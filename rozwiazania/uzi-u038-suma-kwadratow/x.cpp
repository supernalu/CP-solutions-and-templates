#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int SIZE = 24;
ll squares[SIZE];
ll betterSqrt(ll l, ll r, ll k) {
    if (l == r)
        return l;
    ll mid = (l+r+1)/2;
    if (mid*mid <= k)
        return betterSqrt(mid, r, k);
    else
        return betterSqrt(l, mid-1, k);
}
ll compress(ll &k) {
    ll res = betterSqrt(0, 1e9+2, k);
    k -= res*res;
    return res;
}
bool cmp(ll a, ll b) {
return a > b;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < SIZE; i++) 
        squares[i] = i*i;
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> res;
        for (int i = 0; i < 3; i++) 
            res.push_back(compress(n));
        bool done = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    if (squares[i]+squares[j]+squares[k] > n)
                        continue;
                    ll tmp = n-(squares[i]+squares[j]+squares[k]);
                    ll lastNum = betterSqrt(0, 30, tmp);
                    if (lastNum*lastNum != tmp)
                        continue;
                    done = 1;
                    res.push_back(i); res.push_back(j); res.push_back(k); res.push_back(lastNum);
                    break;
                }
                if (done)
                    break;
            }
            if (done)
                break;
        }
        sort(res.begin(), res.end(), cmp);
        for (auto i : res)
            cout << i << ' ';
        cout << '\n';  
        
    }
}