#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 8010;

string s;

int x[2];

vector<int> moves[2];

bool dp[2][2][2*MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    cin >> x[0] >> x[1];

    int tmp = 0;

    int t = 0;

    s+='T';

    dp[1][0][8001] = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'T')
        {
            if (t == 0 && moves[t].empty() && moves[t+1].empty())
                dp[0][0][8001 + tmp] = 1;     
            else
                moves[t].push_back(tmp);

            t = (t+1)%2;

            tmp = 0;
        }
        else
            tmp++;
    }


    /*
    for (int i = 0; i < 2; i++)
    {
        for (auto j : moves[i])
        {
            cout << j << ' ';
        }
        cout << '\n';
    }
    */

    bool res = 1;

    for(int k = 0; k < 2; k++)
    {
        int w = 1;

        //dp[k][0][8001] = 1;

        for (auto i : moves[k])
        {
            for (int j = 0; j <= 2*MAXN; j++)
            {
                if (dp[k][(w+1)%2][j] == 1)
                { 
                    dp[k][w][j-i] = dp[k][w][j+i] = 1;
                }
            }

            w = (w+1)%2;

            for (int j = 0; j <= 2*MAXN; j++)
            {
                dp[k][w][j] = 0;
            }
        }

        w = (w+1)%2;

        if (dp[k][w][x[k] + 8001] == 0)
            res = 0;
    }

    if (res)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    


}