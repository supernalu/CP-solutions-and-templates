#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;



int n, x;

int c[110];

int dp[MAXN];

int main()
{
    cin >> n >> x;

    for (int i = 1; i <= n; i++) 
    { 
        cin >> c[i];

        dp[c[i]] = 1;
    }

    for (int i = 1; i <= x; i++)
    {       
            for (int j = 1; j <= n; j++)
            {                
                    dp[i] +=  dp[max(i - c[j], 0)];

                    dp[i] %= 1000000007;             
            }       
    }

    cout << dp[x];
}