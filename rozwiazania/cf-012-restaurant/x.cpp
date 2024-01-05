#include <bits/stdc++.h>

constexpr int MAXN = 5e5 + 10;

using namespace std;

int n;

vector<pair <int, int>> a(MAXN);

bool cmp (pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}


int dp[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    a[0].first = 0;

    a[0].second = 0;

    a.resize(n+1);

    sort (a.begin(), a.end(), cmp);

    dp[0] = 0;

    int res = 0;
    

    for (int i = 1; i <= n; i++)
    {
        //cout << a[i].first << ' ' << a[i].second << ' ';

        pair <int, int> b = {-1, a[i].first};

        auto it = lower_bound(a.begin(), a.end(), b, cmp);

        auto q = it - a.begin() - 1;

        //cout << q << endl;

        dp[i] = max(dp[i-1], dp[q] + 1);


        res = max(res, dp[i]);

    }
    

    cout << res;
    
}