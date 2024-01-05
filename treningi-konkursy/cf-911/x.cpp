#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
char s[MAXN];
int leftt[MAXN], rightt[MAXN];
int dp[MAXN];
void dfs(int k)
{
    if (leftt[k] == rightt[k] && rightt[k] == 0)
    {
        dp[k] = 0;
        //cout << k << ' ' << dp[k] << '\n';
        return;
    }
    if (leftt[k] != 0)
        dfs(leftt[k]);
    if (rightt[k] != 0)
        dfs(rightt[k]);
    switch(s[k]) {
        case 'U':
            dp[k] = min(dp[leftt[k]], dp[rightt[k]])+1;
            break;
        case 'L':
            dp[k] = min(dp[leftt[k]], dp[rightt[k]]+1);
            break;
        case 'R':
            dp[k] = min(dp[leftt[k]]+1, dp[rightt[k]]);
            break;
    }
    //cout << k << ' ' <<  dp[k] << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> s+1;
        dp[0] = 1e9 + 10;
        for (int i = 1; i <= n; i++)
            cin >> leftt[i] >> rightt[i];
        dfs(1);
        cout << dp[1] << '\n';
    }
}