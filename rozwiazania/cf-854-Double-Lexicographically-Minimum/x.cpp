#include <bits/stdc++.h>

using namespace std;

int t;
string s;
int il[30];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> s; int n = s.size();

        for (char i = 'a'; i <= 'z'; i++)
            il[i-'a'] = 0;
        
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            il[c-'a']++;
        }

        string basic = "";
        string second;

        char i;
        for (i = 'a'; i <= 'z'; i++)
        {
            for (int j = 1; j <= il[i-'a']/2; j++)
                basic += i;

            if (il[i-'a']%2 == 1)
            {
                second = basic + i;
                break;
            }
        }

        i++;

        for ( ; i <= 'z'; i++)
        {
            for (int j = 1; j <= il[i-'a']; j++)
                basic += i;
        }

        reverse(second.begin(), second.end());

        string res = basic + second;

        if (n > 1 && n%2 && res[n/2] == res[n/2-1])
            swap(res[n/2 + 1],res[n/2 + 2]);
        

        cout << res << '\n';
;    }
}

