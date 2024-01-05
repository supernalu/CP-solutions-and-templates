#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int INF = 1e9;

int n;

int d[MAXN];

int q, k;

int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    cin >> q;

    while (q--)
    {
        cin >> k;

        for (int i = 1; i <= n; i++)       
            dp[i] = INF;

        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            int minn = 1e9 + 10;

            for (int j = max(0, i - k); j < i; j++)
            {
                int tmp = dp[j]; 

                if (d[j] <= d[i])
                    tmp++;

                minn = min(minn, tmp);
            }

            dp[i] = minn;
        }

        cout << dp[n] << '\n';

       
    }

}
