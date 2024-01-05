#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5+10;
long long t, n;
long long dp[10];
long long power[10];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int i = 0; i < 10; i++)
        for (int k = 0; k < 10; k++)
            for (int j = 0; j < 10; j++)
                if (i+j+k<10)
                    dp[i+j+k]++;
    //for (int i = 0; i < 10; i++)
        //cout << dp[i] << ' ';
    power[0] = 1;
    for (int i = 1; i < 10; i++)
        power[i] = 10*power[i-1];
    while (t--)
    {
        cin >> n;
        long long res = 1;
        for (int i = 9; i > 0; i--)
        {
            int k = (n%power[i]-n%power[i-1])/power[i-1];
            //out << n%power[i]-n%power[i-1] <<  k << ' ';
            //cout << k << ' ';
            res *= dp[k];
        }
        cout << res << '\n';
            
    }
}