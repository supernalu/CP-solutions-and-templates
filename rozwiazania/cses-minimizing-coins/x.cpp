#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int INF = 1e9 + 10;

int n, x;

int c[110];

int dp[MAXN];

int main()
{
    cin >> n;

    cin >> x;

    for (int i = 0; i <= x; i++)
        dp[i] = INF;

    for (int i = 1; i <= n; i++) 
    { 
        cin >> c[i];

        dp[c[i]] = 1;
    }

    for (int i = 1; i <= x; i++)
    {
        if (dp[i] != 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dp[max(i - c[j], 0)] != INF )
                {
                    dp[i] = min(dp[i], dp[i - c[j]] + 1);
                }
            }
        }
    }
    if (dp[x] == INF)
    {
        cout << "-1";
        return 0;
    }
    cout << dp[x];


    


}