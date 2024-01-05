#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

long long a[MAXN][2];

long long dp[MAXN][2];

int main()
{
    cin >> n;

    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][j];
        }
    }

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = a[1][0];
    dp[1][1] = a[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][j] = max(dp[i-1][(j+1)%2], dp[i-2][(j+1)%2]) + a[i][j];
        }
    }

    cout << max(dp[n][0], dp[n][1]);


}