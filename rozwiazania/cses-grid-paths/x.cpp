#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

int n;

int dp[MAXN][MAXN];

string s[MAXN];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }


    for (int i = 0; i < n; i++)
    {
        if (s[i][0] == '*')
        {
            break;
        }
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[0][i] == '*')  
        {
            break;
        } 
        dp[0][i] = 1;
    }


    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (s[i][j] != '*')
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];

                dp[i][j] %= 1000000007;
            }
        }
    }

    cout << dp[n-1][n-1];
}