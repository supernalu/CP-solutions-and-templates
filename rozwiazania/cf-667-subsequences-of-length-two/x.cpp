#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 210;
int n, k;
char s[MAXN], t[10];
int dp[MAXN][MAXN][MAXN];
int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            for (int h = 0; h < MAXN; h++)
                dp[i][j][h] = -1;
    
    ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    cin >> n >> k >> s+1 >> t+1;
    if (t[1] == t[2])
    {
        int il = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == t[1])
                il++;
        int res = min(n, il+k);
        cout << res*(res-1)/2;
        return 0;
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            for (int h = 0; h <= n; h++)
            {
                if (dp[i][j][h] == -1)
                    continue;
                if (j < k)
                {
                    dp[i+1][j+1][h+1] = max(dp[i+1][j+1][h+1], dp[i][j][h]);
                    dp[i+1][j+1][h] = max(dp[i+1][j+1][h], dp[i][j][h] + h);
                }
                if (s[i+1] == t[1])
                {
                    dp[i+1][j][h+1] = max(dp[i+1][j][h+1], dp[i][j][h]);
                    //cout << i+1 << ' ';
                }
                else if (s[i+1] == t[2])
                    dp[i+1][j][h] = max(dp[i+1][j][h], dp[i][j][h] + h);
                else
                    dp[i+1][j][h] = max(dp[i+1][j][h], dp[i][j][h]);
            }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int h = 0; h <= 3; h++)
                cout << dp[i][j][h] << ' ';
            cout << ' ';
        }
        cout << '\n';
    }
    */
    int res = 0; 
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++)
            res = max(res, dp[n][i][j]);
    cout << res;
    
}