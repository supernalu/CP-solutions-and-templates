#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, k;

int x[MAXN];

int dp[MAXN];

int dp2[MAXN];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    dp[k] = 0;
    dp[k+1] = x[k+1];

    for (int i = k+2; i <= n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2]) + x[i];
    }
    
    dp2[1] = x[1];

    dp2[2] = dp2[1] + x[2];

    for (int i = 3; i <= n; i++)
    {
        dp2[i] = max(dp2[i-1], dp2[i-2]) + x[i];
    }

    int maxi = -1e9;

    for (int i = k; i <= n; i++)
    {
        maxi = max(maxi, dp[i] + dp2[i] - x[i]);
    }

    cout << maxi;

}