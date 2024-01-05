#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e6 + 10;

constexpr int INF = 1e9 + 10;

int n;

long double x[MAXN];

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    dp[0] = -INF;

    for (int i = 1; i <= n+1; i++)
        dp[i] = INF;

    for (int i = 1; i <= n; i++)
        cin >> x[i];
    
    reverse(x + 1, x + n + 1);

    for (int i = 1; i <= n; i++)
    {
        x[i] *= 1000;

        int x1 = (int) x[i];

        auto id = lower_bound(dp, dp + n + 1, x1);

        int t = *id;

        *id = min(t, x1);
    }

    for (int i = n + 1; i >= 0; i--)
    {
        //cout << dp[i] << ' ';

        if (dp[i] != INF)
        {
            cout << i*100;
            return 0;
        } 
    }
}