#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

constexpr int INF = 1e9 + 10;

int n;

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    dp[0] = -INF;

    for (int i = 1; i <= n+1; i++)
        dp[i] = INF;


    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        auto id = lower_bound(dp, dp + n + 1, x);

        int t = *id;

        *id = min(t, x);
    }

    for (int i = n + 1; i >= 0; i--)
    {
        if (dp[i] != INF)
        {
            cout << i;
            return 0;
        } 
    }
}