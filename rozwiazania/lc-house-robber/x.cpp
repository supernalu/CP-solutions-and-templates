#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;

int n;

vector<int> nums(MAXN, 0);

int dp[MAXN];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    dp[0] = 0;

    dp[1] = nums[0];

    dp[2] = nums[1];

    //cout << dp[1] << ' ' <<  dp[2] << ' ';

    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i-3], dp[i-2]) + nums[i-1];
        //cout << dp[i] << ' ';
    }

    cout << max(dp[n], dp[n-1]);

}