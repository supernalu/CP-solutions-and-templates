#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e4 + 10;

constexpr int INF = 1e9;

int n;

vector<int> dp(MAXN, -INF);

pair<int, int> k[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}



int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> k[i].first >> k[i].second;
    }

    sort(k + 1, k + n + 1, cmp);

    dp[0] = 0;



    for (int i = 1; i <= n; i++)
    {
        int L = 0, R = n + 1;
        int res = -1;

        while(L <= R)
        {
            int m = (L + R) / 2;

            if (k[i].first >= k[m].second)
            {
                L = m + 1;
                res = m;
            }
            else
            {
                R = m - 1;
            }
        }
        //cout << k[i].first << ' ' << k[i].second << ' ';
        //cout << k[res].second << endl; 

        if (res == -1)
        {
            dp[i] = max(dp[i-1],  k[i].second - k[i].first);
        }
        else
        {
            dp[i] = max(dp[i-1], dp[res] + k[i].second - k[i].first);
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << ' ';
    }
    */

   cout << dp[n];



}