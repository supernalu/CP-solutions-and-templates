#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;
using ll = long long;


int n; 
ll a[MAXN], b[MAXN];
pair<ll, ll> c[MAXN];
map<pair<ll, ll>, int> m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n; 

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1;  i <= n; i++)
        cin >> b[i];


    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            continue;

        ll d = __gcd(a[i], b[i]);
        c[i] = {-b[i]/d, a[i]/d};
        m[c[i]] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            continue;
        m[c[i]]++;
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            continue;
        res = max(res, m[c[i]]);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
            res++;
    }

    cout << res;

    


}