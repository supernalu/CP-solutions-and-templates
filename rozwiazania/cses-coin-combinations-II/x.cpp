#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int MOD = 1e9 + 7;

int n, m;

int a[110];

int dp[2][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a+1, a + n + 1);

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            dp[i&1][j] = dp[(i+1)&1][j];
        }
        for (int j = a[i]; j <= m; j++)
        {
            dp[i&1][j] = (dp[(i+1)&1][j] + dp[i&1][j-a[i]]);

            if (dp[i&1][j] >= MOD)
                dp[i&1][j] -= MOD;
        }

    }

    cout << dp[n&1][m];


}