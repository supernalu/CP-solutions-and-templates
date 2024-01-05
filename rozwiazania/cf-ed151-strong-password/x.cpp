#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int t, n, m;
char s[MAXN], l[12], r[12];
vector<int> wh[12];
int id[12];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s + 1;
        n = strlen(s+1);
        cin >> m >> l + 1 >> r + 1;

        for (int i = 0; i < 12; i++)
        {
            id[i] = 0;
            wh[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            wh[s[i]-'0'].push_back(i);
        }
        for (int i = 0; i < 10; i++)
            wh[i].push_back(n+1);
        int act = 0;
        for (int i = 1; i <= m; i++)
        {
            if (act == n+1)
                break;
            int maxi = 0;
            for (int j = l[i]-'0'; j <= r[i]-'0'; j++)
            {
                while (wh[j][id[j]] <= act)
                    id[j]++;
                maxi = max(maxi, wh[j][id[j]]);
            }
            act = maxi;
            //cout << act << ' ';
        }

        if (act == n+1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
/*
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int t, n, m;
char s[MAXN], l[12], r[12];
long long dp[MAXN][12];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s + 1;
        n = strlen(s+1);
        cin >> m >> l + 1 >> r + 1;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                //cout << dp[i][j] << ' ';
                if (dp[i][j] == 0)
                    continue;
                if (j+1 <= m && l[j+1] <= s[i+1] && s[i+1] <= r[j+1])
                    dp[i+1][j+1] += dp[i][j];
                dp[i+1][j] += dp[i][j];
            }
            //cout << '\n';
        }
        cout << dp[n][m] << '\n';
    }
}
*/