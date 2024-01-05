#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 5010;


int t, n, k;
int a[MAXN];
ll cold[MAXN];
ll hot[MAXN];
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                dp[i][j] = 1e18+10;
        }
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= k; i++)
            cin >> cold[i];
        for (int i = 1; i <= k; i++)
            cin >> hot[i];
        a[0] = 0;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == j && i != 0)
                    continue;

                if (a[i+1] == a[i])
                    dp[i+1][j] = min(dp[i+1][j],dp[i][j] + hot[a[i+1]]);
                else
                    dp[i+1][j] = min(dp[i+1][j],dp[i][j] + cold[a[i+1]]);
                if (a[i+1] == a[j])
                    dp[i+1][i] = min(dp[i+1][i],dp[i][j] + hot[a[i+1]]);
                else
                    dp[i+1][i] = min(dp[i+1][i], dp[i][j] + cold[a[i+1]]);


                //cout << dp[i][j] << ' ';
            }
            //cout << '\n';
        }


        ll res = 1e18;
        for (int i = 0; i < n; i++)
            res = min(res, dp[n][i]);
        cout << res << '\n';


    }
}