#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

ll n;

ll a[MAXN];

ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        dp[n+1] = 0;

        ll res = 0;

        for (ll i = n; i > 0; i--)
        {
            dp[i] = a[i] + dp[min(i + a[i], n + 1)];

            res = max(res, dp[i]);
        }

        cout << res << '\n';


    }

}