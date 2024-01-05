#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        string s, re;

        vector<int> wys[26];

        cin >> s >> re;

        for (int i = 0; i < s.size(); i++)
        {
            wys[s[i]-'a'].push_back(i);
        }

        int res = 1;

        int u = -1;

        for (int i = 0; i < re.size(); i++)
        {
            if (wys[re[i]-'a'].empty())
            {
                res = -1;

                break;
            }

            auto it = upper_bound(wys[re[i]-'a'].begin(), wys[re[i]-'a'].end(), u);

            //cout << *it << ' ';

            if (it == wys[re[i]-'a'].end())
            {
                res++;

                //cout << res << ' ';

                u = *(upper_bound(wys[re[i]-'a'].begin(), wys[re[i]-'a'].end(), -1));

                //u = -1;
            }
            else
            {
                u = *it;
            }

        }

        cout << res << '\n';



    }
}