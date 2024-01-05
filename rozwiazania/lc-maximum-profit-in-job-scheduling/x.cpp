#include <bits/stdc++.h>

constexpr int MAXN = 5e4 + 10;

using namespace std;

int n;

vector<int> startTime(MAXN), endTime(MAXN), profit(MAXN);

vector<int> cop(MAXN);

int dp[MAXN];

bool cmp(int a, int b)
{
    return endTime[a] < endTime[b];
}

int main()
{
    cin >> n;

    startTime[0] = 0; endTime[0] = 0; profit[0] = 0;

    startTime.resize(n+1); endTime.resize(n+1); profit.resize(n+1);

    cop.resize(n+1);

    vector<int>s(n+1);


    for (int i = 0; i <= n; i++)
    {
        s[i] = i;
    }

    

    for (int i = 1; i <= n; i++)
    {
        cin >> startTime[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> endTime[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> profit[i];
    }

    sort(s.begin(), s.end(), cmp);

    for (int i = 0; i <= n; i++)
    {
        //cout << s[i] << ' ';

        cop[i] = endTime[i];
    }

    dp[0] = 0;

    dp[s[1]] = profit[s[1]]; 

    for (int i = 2; i <= n; i++)
    {
        auto j = upper_bound(endTime.begin(), endTime.end(), startTime[s[i]]);

        if (endTime[s[j - endTime.begin() - 1]] > startTime[s[i]])
        {
            dp[i] = dp[i-1];
            continue;
        }

        dp[i] = max(dp[i-1], dp[s[j - endTime.begin() - 1]] + profit[s[i]]);



        cout << dp[i] << ' ' << j - endTime.begin() - 1 << ' ';
    }

    cout << dp[n];



}