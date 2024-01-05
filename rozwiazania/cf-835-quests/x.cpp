#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;

int t, n;
ll c, d, a[MAXN];

ll binSearch(ll l, ll r)
{
    if (l == r)
        return r;

    ll mid = (l+r+1)/2;

    ll sum = 0;
    int id = 0;

    for (int i = 0 ; i < d; i++)
    {
        sum += a[max(n-id, 0)];
        id = (id+1)%mid;
    }

    

    if (sum >= c)
        return binSearch(mid, r);
    else
        return binSearch(l, mid-1);
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> c >> d;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        sort (a + 1, a + n + 1);

        ll res = binSearch(0, d+10);

        if (res == d+10)
            cout << "Infinity\n";
        else if (res == 0)
            cout << "Impossible\n";
        else
            cout << res-1 << '\n';


    }
}