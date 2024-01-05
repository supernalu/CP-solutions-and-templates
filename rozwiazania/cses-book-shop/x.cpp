#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

constexpr int INF = 1e9;

int n, x;

int h[MAXN];

int s[MAXN];

int dp[MAXN][100010];



int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = -INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (dp[i][j] != -INF)
            {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
                
                if (j + h[i+1] <= x)
                    dp[i + 1][j + h[i + 1]] =  max(dp[i][j] + s[i + 1], dp[i + 1][j + h[i + 1]] );

                //cout << i << ' ' << j << endl;
            }
        }
    }


    int maxi = 0;


    for (int j = 0; j <= x; j++)
    {
        maxi = max(dp[n][j], maxi);
    }

    cout << maxi;
    

    
}