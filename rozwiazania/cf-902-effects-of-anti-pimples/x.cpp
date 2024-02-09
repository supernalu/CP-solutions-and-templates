#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
constexpr int MAXN = 1e5 + 10;
int  n;
ll a[MAXN];
vector<ll> wh[MAXN];
vector<bool> done(MAXN, 0);
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
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        wh[a[i]].push_back(i);
    }
    ll notDone = n;
    ll res = 0;
    for (ll r = MAXN-1; r >= 0; r--) {
        if (wh[r].empty())
            continue;
        set<ll> s;
        for (auto i : wh[r]) {
            if(done[i])
                continue;
            //cout << i << ' ';
            for (ll j = 1; j*j <= i; j++) {
                if (i%j != 0)
                    continue;
                //cout << j << ' ';
                if (done[i/j] == 0)  {
                    s.insert(i/j);
                    done[i/j] = 1;
                    notDone--;
                }
                if (done[j] == 0) {
                    s.insert(j);
                    done[j] = 1;
                    notDone--;
                }
            }
        }
        //cout << s.size() << ' ' << notDone << '\n';
        res = (res+(((((fastExp(2, (ll)(s.size()), MOD)-1+MOD)%MOD)*fastExp(2, notDone, MOD))%MOD)*r)%MOD)%MOD;
        //cout << res << '\n';
    }
    cout << res;
    
}