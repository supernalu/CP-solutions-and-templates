#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 3e5 + 10;

int t;
ll n, dp[16];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> t;

    dp[0] = 1;
    dp[1] = 8;

    for (int i = 2; i <= 15; i++)
        dp[i] = 9*dp[i-1];


    while (t--)
    {
        cin >> n;

        vector<int> res;

        for (int i = 15; i >= 0; i--)
        {   
            if (dp[i] >= n)
                continue;
            
            //cout << i << ' ';
            int st = 0;
            if (i == 0)
                st = 1;

            for (int j = st; j < 9; j++)
            {
                n -= dp[i];
                //cout << n << ' ';


                if (n - dp[i] < dp[i-1])
                {
                    
                    int tmp = j;
                    
                    if (j >= 4)
                        tmp++;

                    res.push_back(tmp);
                    break;
                }
            }
        }

        reverse(res.begin(), res.end());

        for (auto i : res)
            cout << i;
        cout << '\n';

        
        




    }
}