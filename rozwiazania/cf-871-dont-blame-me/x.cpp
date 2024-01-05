#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 1e9 + 7;
int t, n, k;
int bitsLit[64];
int dp[MAXN][64];
int a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tmp = 1;
    for (int k = 0; k < 6; k++)
    {
        for (int i = 63; i >= 0; i--)
        {
            if (bitsLit[i] != 0)
                continue;
            if (i-tmp==0)
            {
                bitsLit[i] = 1;
                break;
            }
            if (bitsLit[i-tmp] == 0)
                continue;
            bitsLit[i] = bitsLit[i-tmp]+1;
        }
        tmp *= 2;
    }  
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 64; j++)
                dp[i][j] = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i+1][a[i+1]]++;
            for (int j = 0; j < 64; j++)
            {
                if (dp[i][j] == 0)
                    continue;
                dp[i+1][(j & a[i+1])] = (dp[i][j] + dp[i+1][(j & a[i+1])])%MOD;
                dp[i+1][j] = (dp[i][j] + dp[i+1][j])%MOD;
            }
        } 
        int res = 0;
        for (int i = 0; i < 64; i++)
            if (bitsLit[i] == k)
                res = (res+dp[n][i])%MOD;
        cout << res << '\n';
    }
}