#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;
constexpr ll INF = 1e18 + 10;

int t, n;
ll dp[MAXN][3][2];
ll a[MAXN], h;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> h;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            
            for (int g = 2; g >= 0; g--)
                for (int b = 1; b >= 0; b--)
                    dp[i][g][b] = -INF;
                    
            
        }
        sort(a+1, a+n+1);

        
        dp[n+1][0][0] = -INF; dp[n+1][1][0] = -INF; dp[n+1][2][0] = -INF; dp[n+1][1][1] = -INF; dp[n+1][2][1] = -INF; dp[n+1][0][1] = -INF;
        dp[1][0][0] = h;

        for (int i = 1; i <= n; i++)
        {
            for (int g = 0; g <= 2; g++)
            {
                for (int b = 0; b <= 1; b++)
                {
                    if (dp[i][g][b] > a[i])
                        dp[i+1][g][b] = max(dp[i+1][g][b], dp[i][g][b] + a[i]/2);
                    if (g < 2)
                        dp[i][g+1][b] = max(dp[i][g+1][b], dp[i][g][b]*2);
                    if (b < 1)
                        dp[i][g][b+1] = max(dp[i][g][b+1], dp[i][g][b]*3); 

                    //cout << dp[i][g][b] << '|';
                }
                //cout << ' ';
            }
            //cout << '\n';
            
        }



        for (int i = n+1; i > 0; i--)
        {
            if (dp[i][2][1] > 0)
            {
                cout << i-1 << '\n';
                break;
            }
        }
        


    }
}