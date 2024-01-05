#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 4e4 + 10;
constexpr int MOD = 1e9 + 7;

int t, n;
vector<int> testcase;

int dp[MAXN];

int rev(int k)
{
    int reversed_number = 0, remainder;

    while(k != 0) {
        remainder = k % 10;
        reversed_number = reversed_number * 10 + remainder;
        k /= 10;
    }

    return reversed_number;
}

int main()
{
    cin >> t;

    while (t--)
    {
        int m;

        cin >> m;

        testcase.push_back(m);

        n = max(m, n);
    }

    dp[0] = 1;
    vector<int> pali;

    for (int i = 1; i <= n; i++)
    {
        //cout << rev(i) << ' ';

        if (i == rev(i))
        {
            pali.push_back(i);
        }
    }

    for (auto i : pali)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] += dp[j-i];  
            dp[j] %= MOD;
        }
    }

    for (auto i : testcase)
    {
        cout << dp[i] << '\n';
    }
}