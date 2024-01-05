#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t;

int n;

int a[MAXN];

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

        if (n > 99)
        {
            cout << "YES\n";

            continue;
        }

        sort(a + 1, a + n + 1);

        bool con = 0;

        int sum  = 0;

        for (int i = 1; i < n; i++)
        {
            sum += a[i];

            if (a[i] == a[i+1])
            {
                cout << "YES\n";

                con = 1;

                break;
            }
        }

        if (con)
            continue;

        int dp[5100];

        for (int i = 1; i <= sum; i++)
        {
            dp[i] = 0;
        }

        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= a[i]; j--)
            {
                dp[j] += dp[j-a[i]];

                if (dp[j] >= 2)
                {
                    cout << "YES\n";

                    con = 1;

                    break;
                }
            }

            if (con)
                break;
        }

        if (con)
            continue;

        cout << "NO\n";
    }
}