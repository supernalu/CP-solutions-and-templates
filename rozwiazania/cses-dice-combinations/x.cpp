#include <bits/stdc++.h> 

using namespace std;

constexpr int MAXN = 1e6 + 10;

int dp[MAXN];

int n;

int main()
{
    cin >> n;

    dp[1] = 1;

    for (int i = 2; i <= 6; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] += dp[j];
        }

        dp[i]++;
    }

    for (int i = 7; i <= n; i++)
    {
        for (int j = i-6; j < i; j++)
        {
            dp[i] += dp[j];
            dp[i] %= 1000000007;
        }
    }

    cout << dp[n];
}