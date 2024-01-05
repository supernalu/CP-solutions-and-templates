#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 310;
constexpr int MOD = 998244353;
int n, a[MAXN], dp[MAXN][2*MAXN*MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;  i <= n; i++)
    {
        cin >> a[i];
    }
    dp[2][MAXN*MAXN + a[2]] = 1;

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < 2*MAXN*MAXN; j++)
        {
            if (dp[i][j] == 0)
                continue;
            if (j == MAXN*MAXN)
            {
                dp[i+1][a[i+1]+j] = (dp[i+1][a[i+1]+j]+dp[i][j])%MOD;
            }
            else
            {
                int val = j-MAXN*MAXN;
                dp[i+1][a[i+1]+MAXN*MAXN-val] = (dp[i+1][a[i+1]+MAXN*MAXN-val]+dp[i][j])%MOD;
                dp[i+1][a[i+1]+MAXN*MAXN+val] = (dp[i+1][a[i+1]+MAXN*MAXN+val]+dp[i][j])%MOD;
            }

        }
    }
    int res = 0;
    for (int i = 0; i < 2*MAXN*MAXN; i++)
        res = (res+dp[n][i])%MOD;
    cout << res;
}