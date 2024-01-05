#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n, a[MAXN];
vector<int> wh[MAXN];
int last[MAXN];
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
            wh[i].clear();
        }
        for (int i = 1; i <= n; i++)
            wh[a[i]].push_back(i);
        for (int i = 1; i <= n; i++)
        {
            if (wh[i].empty())
                continue;
            last[wh[i][0]] = -1;
            for (int j = 1; j < wh[i].size(); j++)
                last[wh[i][j]] = wh[i][j-1];
        }
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (last[i] == -1)
            {
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = max({dp[i-1], dp[last[i]]+i-last[i], dp[last[i]-1]+i-last[i]+1});
        }                
        cout << dp[n] << '\n';
    }
}