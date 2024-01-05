#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

constexpr int INF = 1e9 + 10;

int n;

int dp[MAXN];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        dp[i] = INF;
    }
    dp[n] = 0;

    for (int i = n; i >= 0; i--)
    {
        string s = to_string(i);

        if (dp[i] != INF)
        {            

            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] != '0')
                {
                    int pom = (int)s[j] - 48;
                    
                    dp[i - pom] = min(dp[i-pom], dp[i] + 1);
                }
            }
            
        }
        
    }

    cout << dp[0];
}