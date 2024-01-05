#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

constexpr int INF = 1e9;

int T, A;

int n;

int t[MAXN], a[MAXN], w[MAXN];

int dp[MAXN][30][80];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T >> A;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> a[i] >> w[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            for (int k = 0; k <= A; k++)
            {
                dp[i][j][k] = INF;
            }
        }
    }


    dp[0][0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            for (int k = 0; k <= A; k++)
            {
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);

                dp[i+1][min(j + t[i+1], T)][min(k + a[i+1], A)] = min(dp[i+1][min(j + t[i+1], T)][min(k + a[i+1], A)], dp[i][j][k] + w[i+1]);
            }
        }
    }

    cout << dp[n][T][A];
}