#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;

constexpr int INF = 1e9;

int n;

vector<vector<int>> matrix(MAXN, vector<int>(MAXN));

int dp[MAXN][MAXN];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = INF;
        }
    }

    //cout << endl;
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
        //cout << dp[0][i] << ' ';
    }
    //cout << endl;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + matrix[i][0];
        dp[i][n-1] = min(dp[i-1][n-1], dp[i-1][n-2]) + matrix[i][n-1];

        //cout << dp[i][0] << ' ';
        for (int j = 1; j < n-1; j++)
        {
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1])) + matrix[i][j];
            //cout << dp[i][j] << ' ';
        }
        //cout << dp[i][n-1] << endl;
    }

    int res = 1e9;
    
    for (int i = 0; i < n; i++)
    {
        res = min(res, dp[n-1][i]);
    }

    cout << res;


}