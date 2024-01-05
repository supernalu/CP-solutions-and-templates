#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;

int n;

int k;

vector<int> prices(1010);

int dp[1010][210];

int main()
{
    cin >> n;

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    for (int i = 0; i < n; i++)
    {
       for (int j = 1; j <= 2*k; j++)
       {
           dp[i][j] = -INF;
       }
    }

    

    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j <= 2*k; j++)
       {
            if (j > i)
                continue;

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

            if (j%2 == 0)
            {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] - prices[i]);
            }
            else
            {
                int maxi = -INF;

                for (int u = j; u <= i; u++)
                {
                    maxi = max(maxi, dp[u][j]);
                }

                dp[i+1][j+1] = max(dp[i+1][j+1], maxi + prices[i]);
            }
       }
       
    }

    

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 2*k; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    int maxi = 0;
    for (int i = 0; i <= 2*k; i++)
    {
        maxi = max(maxi, dp[n][i]);
    }

    cout << maxi;
}