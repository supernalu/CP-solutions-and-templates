#include <bits/stdc++.h>

using namespace std;

class Solution {
private: 
    const int MAXN = 1e4 + 10;

    const int INF = 1e9;

    vector <int> sq;

    vector<int>dp;

public:
    int numSquares(int n) {
        dp.assign(MAXN, INF);
        for(int i = 1; i <= n; i++)
        {
            if (i*i <= n)
            {
                sq.push_back(i*i);

                dp[i*i] = 1;
            
            }
            else
                break;
        }

        for (int i = 2; i <= n; i++)
        {
            if (dp[i] != 1)
            {
                for (int j = 1; j*j < i; j++)
                {
                    dp[i] = min(dp[i], dp[j*j] + dp[i-j*j]);
                }   
            }
            //cout << i << ": " << dp[i] << endl;
        }
        return(dp[n]);
    
        
    }
};

int n;

int main()
{
    Solution lmao;

    cin >> n;

    cout << lmao.numSquares(n);
}








    

   




