#include <bits/stdc++.h>

constexpr int MAXN = 1e5 + 10;
constexpr int MAXM = 110;
constexpr int MOD = 1e9 + 7;

using namespace std;

int n, m; 

int x[MAXN];

unsigned dp[MAXN][MAXM];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int i = 0; i <= m+1; i += 3)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (x[i] != 0)
        {
            dp[i][x[i]] = dp[i-1][x[i]-1] + dp[i-1][x[i]+1] + dp[i-1][x[i]];

            while (dp[i][x[i]] >= MOD)
                dp[i][x[i]] -= MOD;

            continue;
        }

        for (int j = 1; j <= m; j++)
        {
             dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] + dp[i-1][j];

            while (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }   
    }

    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    unsigned res = 0;

    for (int i =  1; i <= m; i++)
    {
        res += dp[n][i];

        if (res > MOD)
            res -= MOD;
    }

    cout << res;
}