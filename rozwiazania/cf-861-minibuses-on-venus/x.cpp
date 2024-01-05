#include <bits/stdc++.h>

using namespace std;
long long n, k, m, dp[34][104][34], dpAll[104][34];
long long res = 1;

int main()
{
    cin >> n >> k >> m;

    for (long long base = 0; base < k; base++)
    {
        dp[base][0][0] = 1;
        for (long i = 0; i < n; i++)
        {
            for (long long j = 0; j < k; j++)
            {
                if (dp[base][i][j] == 0)
                    continue;
                for (long long h = 0; h < k; h++)
                {
                    if ((h*2)%k == base)
                        continue;
                    dp[base][i+1][(j+h)%k] = (dp[base][i+1][(j+h)%k]+dp[base][i][j])%m;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        res = (res*k)%m;
    for (int i = 0; i < k; i++)
    {
        //cout << dp[i][n][(2*i)%k] << ' ';
        res = (m+res-dp[i][n][i])%m;
    }
    


    cout << res << '\n';

}