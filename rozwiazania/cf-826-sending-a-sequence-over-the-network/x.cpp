#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t, n;

int a[MAXN];

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        dp[n+1] = 1;

        for (int i = 1; i <= n; i++)
            dp[i] = 0;

        for (int i = n; i > 0; i--)
        {
            if (dp[i+1] && i - a[i] > 0)
                dp[i-a[i]] = 1;

            if (i+a[i]<= n && dp[i+a[i]+1])
                dp[i] = 1;
        }

        if (dp[1])
            cout << "YES\n";
        else
            cout << "NO\n";


    }
}