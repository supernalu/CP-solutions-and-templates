//30

#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5e3 + 10;

constexpr int MAXNN = 5e5 + 10;

constexpr int MOD = 1e9 + 7;

int t, n;

int dp[MAXN][MAXN];

pair<int, int> brick[MAXNN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        bool poss = 1;
        
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> brick[i].first >> brick[i].second;

            if (brick[i].first != brick[i].second)
                poss = 0;
        }

        if (poss)
        {
            long long res1 = 0, res2 = 1;

            int tmp = 1;

            sort(brick + 1, brick + n + 1);

            for (int i = 1; i <= n; i++)
            {
                if (brick[i].first != brick[i-1].first)
                {
                    res1++;

                    res2 *= tmp;

                    res2 %= MOD;

                    tmp = 1;
                }
                else
                {
                    tmp++;
                }
            }

            cout << res1 << ' ' << res2 << '\n';
        }
        else
        {

        brick[0] = {1e9 + 10, 1e9 + 10};

        dp[0][0] = 1;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (dp[i][j] == 0)
                    continue;

                for (int k = 0; k <= n; k++)
                {
                    if (brick[k].first < brick[j].first && brick[k].second < brick[j].second)
                    {
                        dp[i+1][k] += dp[i][j];

                        dp[i+1][k] %= MOD;
                    }
                }
            }
        }

        
        for (int i = n; i >= 0; i--)
        {
            long long sum = 0;

            for (int j = n; j >= 0; j--)
            {
                //cout << dp[i][j] << ' ';

                sum += dp[i][j];

                sum %= MOD;              
            }
            //cout << endl;

            if (sum != 0)
            {
                cout << i << ' ' << sum << '\n';
                break;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = 0;
            }
        }

        }
    }
}