#include <bits/stdc++.h>

using namespace std;

int t;
string s; int k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s; cin >> k;

        vector<char>res;
        int j = -1;
        char tmp2 = ':';
        for (int i = 0; i <= k; i++)
        {
            if (s[i] == '0')
                break;

            if (s[i] < tmp2)
            {
                tmp2 = s[i];
                j = i;
            } 
        }
        k -= j;
        res.push_back(s[j]);  

        while(k > 0)
        {
            int tmp = -1;
            tmp2 = ':';
            for (int i = j+1; i <= k+j+1; i++)
            {
                if (s[i] < tmp2)
                {
                    tmp2 = s[i];
                    tmp = i;
                } 
            }
            k -= (tmp - j - 1);
            res.push_back(s[tmp]);

            j = tmp;
        }
        for (int i = j+1; i < s.size(); i++)
            res.push_back(s[i]);

        //cout << res.size() << ' ';

        for (auto i : res)
        {
            if (i > 57 || i < 48)
                continue;
            cout << i;
        }
        cout << '\n';
    }
}