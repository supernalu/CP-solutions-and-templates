#include <bits/stdc++.h>

using namespace std;

//constexpr int MAXN = 1e7 + 10;

constexpr long long MOD = 1e9 + 7;

int n;

long long dp[2][4];

int main()
{
    cin >> n;

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j != k)
                    dp[(i+1)%2][k] = (dp[(i+1)%2][k] + dp[i%2][j])%MOD;
            }
            if (i != n)
            {
                dp[i%2][j] = 0;
            }
        }
    }

    cout << dp[n%2][0];
}