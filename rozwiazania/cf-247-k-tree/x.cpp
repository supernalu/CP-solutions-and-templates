#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;

constexpr int MOD = 1e9 + 7;

int n, q, d;

long long dp[MAXN][MAXN][2];

int main()
{
    cin >> n >> q >> d;

    for (int i = 0; i <= n; i++)
    {
        dp[i][0][0] = 1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                for (int w = 1; w <= q; w++)
                {
                    if (j + w > n)
                        break;
                    
                    if (k == 1 || w >= d)
                    {
                        dp[i+1][j+w][1] += dp[i][j][k];

                        dp[i+1][j+w][1] %= MOD;
                    }
                    else
                    {
                        dp[i+1][j+w][0] += dp[i][j][k];

                        dp[i+1][j+w][0] %= MOD;
                    }
                }
            }
        }
    }

    cout << dp[n][n][1];

    
}