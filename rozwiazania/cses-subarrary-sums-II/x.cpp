#include <bits/stdc++.h>
#define ll long long 

using namespace std;
constexpr int MAXN = 2e5 + 20;

int n, x;
ll pref[MAXN];
map<ll, ll> m;
ll res = 0;

int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        ll a; cin >> a;

        pref[i] = pref[i-1]+a;
        m[pref[i]] = 0;
        m[pref[i] - x] = 0;
    } 
    
    m[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        res += m[pref[i]-x];
        m[pref[i]]++;
    }

    cout << res;

}