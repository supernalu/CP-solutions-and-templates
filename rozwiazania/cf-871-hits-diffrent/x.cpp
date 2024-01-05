#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6;
using ll = long long;

int t, n;
ll dp[2030][2030];
pair<int, int> lmao[MAXN];



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    lmao[1] = {1,1};
    dp[1][1] = 1;
    int x = 1, y = 2;

    for (ll i = 2; i<= MAXN; i++)
    {
        if (x > y)
        {
            y++;
            x = 1;
        }

        lmao[i] = {x, y};
        dp[x][y] = dp[x][y-1]+dp[x-1][y-1]-dp[x-1][y-2] + i*i;
        x++;
    }

    cin >> t;

    while (t--)
    {
        cin >> n;

        cout << dp[lmao[n].first][lmao[n].second] << '\n';
    }
}

