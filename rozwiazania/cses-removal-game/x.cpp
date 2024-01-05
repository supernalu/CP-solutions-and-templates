//!Do poprawy!

#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 5e3+10;

int n;
ll a[MAXN];
pair<ll, ll> dp[MAXN][MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    a[0] = -1e16;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n==1)
    {
        cout << a[1];
        return 0;
    }

    for (int i = 0; i <= n; i++)
    {
        dp[i][i] = {a[i], 0};
        //cout << dp[i][i].first << ' ' << dp[i][i].second << "; ";
    }
    //cout << '\n';

    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i+1])
            dp[i][i+1] = {a[i+1], a[i]};
        else
            dp[i][i+1] = {a[i], a[i+1]};
        //cout << dp[i][i+1].first << ' ' << dp[i][i+1].second << "; ";
    }
    //cout << '\n';
    
    for (int k = 2; k < n; k++)
    {
        for (int i = 1; i + k <= n; i++)
        {
            if (!(k%2))
            {
                if (a[i] + dp[i+2][i+k].first >  dp[i][i+k-2].first+a[i+k])
                    dp[i][i+k] = {a[i] + dp[i+2][i+k].first, dp[i+1][i+k].second};
                else
                    dp[i][i+k] = {dp[i][i+k-2].first+a[i+k], dp[i][i+k-1].second};         
            }
            else
            {
                if (a[i] + dp[i+2][i+k].second > dp[i][i+k-2].second+a[i+k])
                    dp[i][i+k] = {dp[i+1][i+k].first, a[i] + dp[i+2][i+k].second};
                else
                    dp[i][i+k] = {dp[i][i+k-1].first, a[i+k] + dp[i][i+k-2].second};
            }
            //cout << dp[i][i+k].first << ' ' << dp[i][i+k].second << "; ";
        }
        //cout << "\n";
    }
    if (n%2)
        cout << dp[1][n].first;
    else
        cout << dp[1][n].second;
}