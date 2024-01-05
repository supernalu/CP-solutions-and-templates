#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

constexpr long long INF = 1e18 + 10;

int t, n, k;

long long a[31][MAXN];

long long dp[31][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 31; j++)
                dp[j][i] = -INF;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> a[0][i];
            for (int j = 1; j < 31; j++)
                a[j][i] = a[j-1][i]/2;
        }

        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                dp[j][i+1] = max(dp[j][i+1], dp[j][i] + a[j][i+1]-k);
                dp[min(30, j+1)][i+1] = max(dp[min(30, j+1)][i+1], dp[j][i] + a[min(30, j+1)][i+1]);
            }
        }
        long long res = 0;
        for (int i = 0; i < 31; i++)
            res = max(res, dp[i][n]);
        cout << res << '\n';    
    }
}