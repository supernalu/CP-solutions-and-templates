#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

long long a[MAXN];

long long dp[MAXN];

int maxa = 0;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int b;

        cin >> b;

        a[b]++;

        maxa = max(maxa, b);
    }

    dp[0] = 0;

    dp[1] = a[1];

    dp[2] = dp[0] + 2*a[2];

    for (int i = 3; i <= maxa; i++)
        dp[i] = max(dp[i-3], dp[i-2]) + i*a[i];
      
    cout << max(dp[maxa], dp[maxa-1]);
}