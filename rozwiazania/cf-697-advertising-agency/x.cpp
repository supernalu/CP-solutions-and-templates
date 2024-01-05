#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e3 + 10;
constexpr long long MOD = 1e9 + 7;

int t;

int n, k;

int a[MAXN];
int b[MAXN];
int dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= k; i++)
            b[i] = a[n-i+1];
        for (int i = 0; i <= n+1; i++)
            for (int j = 0; j <= n+1; j++)
               dp[i][j] = 0;
        dp[n+1][0] = 1;
        for (int i = n+1; i > 0; i--)
        {
            for (int j = 0; j <= k; j++)
            {
                if (a[i-1] == b[j+1])
                    dp[i-1][j+1] = (dp[i-1][j+1] + dp[i][j])%MOD;
                dp[i-1][j] = (dp[i-1][j] + dp[i][j])%MOD;
            }
        }
        /*
        for (int i = 1; i <= n+1; i++)
        {
            for (int j = 0; j  <= k; j++)
                cout << dp[i][j] << ' ';
            cout << '\n';
        }*/
    
        cout << dp[1][k] << '\n';
        
    }
}