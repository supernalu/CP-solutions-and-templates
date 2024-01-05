#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 998244353;
ll t, n, m;
ll a[MAXN];
ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        bool poss = 1;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            if (a[i-1]%a[i] != 0)
            {
                poss = 0;
            }

        }

        if (!poss)
        {
            cout << "0\n";
            continue;
        }

        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i-1]*(m/a[i] - (m)/a[i-1]))%MOD;
            cout << dp[i] << ' ';
        }

        cout << dp[n] << '\n';

    }
}