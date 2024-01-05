#include <bits/stdc++.h>

constexpr int MAXN = 3e5 + 10;

constexpr int MOPADULO = 1e9 + 7;

using namespace std;

int n; 

long long a[MAXN];

long long pref[MAXN];

long long dp[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        pref[i] = a[i] + pref[i-1];

        pref[i] %= MOPADULO;
    }

   

    

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int q = pref[i] - pref[j];

            if (q < 0)
                q = MOPADULO + q;

            

            if (dp[j] == 0 || ((q%MOPADULO)%2) == 1)
                continue;

            


            dp[i] += dp[j];

            dp[i] %= MOPADULO;
        }

        
    }

    cout << dp[n];
}