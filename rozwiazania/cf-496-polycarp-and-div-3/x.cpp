#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

char s[MAXN];

int pref[MAXN];

int n;

int dp[MAXN];

vector<int> wys[3];

int main()
{
    cin >> s+1;

    n = strlen(s+1);

    for (int i = 1; i <= n; i++)
    {
        s[i] = ((s[i]-48)%3)+48;
    }

    for (int i = 1; i <= n; i++)
    {
        //cout << s[i];

        pref[i] = ((s[i]-48) + pref[i-1])%3;
    }

    for (int i = 1; i <= n; i++)
    {
        //cout << pref[i] << ' ';
    }

    if (pref[1] == 0)
    {
        dp[1] = 1;
    }
    else
    {
        dp[1] = 0;
    }

    wys[pref[0]].push_back(0);

    wys[pref[1]].push_back(1);

    for (int i = 2; i <= n; i++)
    {
        if (wys[pref[i]].empty())
        {
            dp[i] = dp[i-1];
        }
        else
        {
            dp[i] = max(dp[i-1], dp[wys[pref[i]][wys[pref[i]].size()-1]] + 1);
        }

        wys[pref[i]].push_back(i);

        //cout << dp[i] << ' ';
    }

    cout << dp[n];


}