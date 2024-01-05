#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n, m;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        int res = 0;
        multiset<ll> s;
        ll sum = 0;
        for (int i = m; i > 1; i--)
        {
            sum += a[i];

            if (a[i] > 0)
                s.insert(a[i]);
            if (sum <= 0)
                continue;

            ll tmp = *(s.rbegin()); s.erase(--s.end());
            sum -= 2*tmp; res++;     
        }

        s.clear();
        sum = 0ll;
        for (int i = m+1; i <= n; i++)
        {
            sum += a[i];

            if (a[i] < 0)
                s.insert(a[i]);
            if (sum >= 0)
                continue;

            ll tmp = *(s.begin()); s.erase(s.begin());
            sum -= 2*tmp; res++;     
        }
        cout << res << '\n';
    }
}