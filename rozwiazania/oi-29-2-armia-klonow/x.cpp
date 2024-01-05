#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 10;

constexpr long long INF = 1e18 + 10;

int n, a, b;

long long Res = INF;

long long  dp[MAXN][MAXN];

map<pair<int, int>, long long> d;

int solve(long long i, long long j, long long res)
{
    if (d[{i,j}] != 0)
        return d[{i, j}];

    if (i > n)
        return res;

        if (i <= j)
        {
            return solve(i+j, j, res + b);
        }  

    return d[{i,j}] = min(solve(i,i, res + a), solve(i+j, j, res + b));
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    if (n <= 1000)
    {
        for (int i = 0; i <= n+1; i++)
        {
            for (int j = 0; j <= n+1; j++)
            {
                dp[i][j] = INF;
            }
        }

        dp[1][0] = 0;

        for (int i = 0; i <= n+1; i++)
        {
            for (int j = 0; j <= n+1; j++)
            {
                if (dp[i][j] == INF)
                {
                    continue;
                }
            
                dp[i][i] = min(dp[i][j] + a, dp[i][i]);
                

                dp[min(i+j, n + 1)][j] = min(dp[i][j] + b, dp[min(i+j, n+1)][j]);
            }
        }

        for (int i = 0; i <= n + 1; i++)
            Res = min(Res, dp[n+1][i]);
        

        cout << Res;

    }
    else
    {
        cout << solve(1, 1, a);
    }

}