#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 210;

constexpr int MAXW = 160;

constexpr int MAXRES = 1e6;

char w[MAXW];

int n;

int dp[MAXW], parent[MAXW];

int dl[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w+1;
    cin >> n;

    int s = strlen(w+1);
    dp[0] = 1;
    parent[0] = 0;
    dl[0] = MAXRES;

    for (int k = 1; k <= n; k++)
    {
        char tmp[MAXW];

        cin >> tmp+1;

        dl[k] = strlen(tmp+1);

        for (int i = s-dl[k]+1; i >= 1; i--)
        {
            bool pos = 1;

            //cout << i << ' ';

            for (int j = 1; j <= dl[k]; j++)
            {
                if (w[i+j-1] != tmp[j])
                {
                        pos = 0;

                        break;
                }
            }

            if (pos)
            {
                dp[i+dl[k]-1] = min(dp[i-1] + dp[i+dl[k]-1], MAXRES);

                if (parent[i+dl[k]-1] == 0 && dp[i+dl[k]-1] != 0)
                    parent[i+dl[k]-1] = k;
            }
        }


        /*
        for (int i = 0; i <= s; i++)
            cout << dp[i] << ' ';

        cout << '\n';
        */
        
    }

    if (dp[s] == 0)
    {
        cout << "NIE";
        return 0;
    }

    cout << dp[s] << '\n';

    int h = s;

    vector<int>res;

    while (h > 0)
    {
        res.push_back(parent[h]);
        h -= dl[parent[h]];
    }

    if (res[res.size()-1] == 0)
        res.pop_back();



    reverse(res.begin(), res.end());

    for (auto i : res)
        cout << i << '\n';
    
}