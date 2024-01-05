#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>

using namespace std;

constexpr int MAXN = 200 + 10;

int t;

char s[MAXN];

int dp[MAXN][MAXN];

pair<int,int> parent[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s + 1;

        int n = strlen(s+1);

        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 1;

            parent[i][i] = {i, i};

            parent[i+1][i] = {0, 0};
        }



        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                if (s[j] == s[j+i])
                {
                    dp[j][j+i] = 2 + dp[j+1][j+i-1];

                    parent[j][j+i] = {j+1, j+i-1};
                }
                else
                {
                    dp[j][j+i] = max(dp[j][j+i-1], dp[j+1][j+i]);

                    if (dp[j][j+i-1] >= dp[j+1][j+i])
                        parent[j][j+i] = {j, j+i-1};
                    else
                        parent[j][j+i] = {j+1, j+i}; 
                }  
            }
        }

        //cout << dp[1][n] << ' ';

        pair <int, int> i = {1, n};

        vector<char> res;

        while (i.first != i.second)
        {
            if (parent[i.first][i.second] == make_pair(i.first + 1, i.second - 1))
                res.push_back(s[i.first]);

            i = parent[i.first][i.second];      
        
        }

        //reverse(res.begin(), res.end());
        
        for (auto j : res)
            cout << j;

        if (i.first != 0)
            cout << s[i.first];

        reverse(res.begin(), res.end());
        
        for (auto j : res)
            cout << j;

        cout << '\n';

    }

}