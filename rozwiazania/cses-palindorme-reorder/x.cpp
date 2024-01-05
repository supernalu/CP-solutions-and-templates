#include <bits/stdc++.h>

using namespace std;

string s;

int wys[30];

int main()
{
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        wys[s[i]-'A']++;
    }

    int il = 0;

    for (int i = 0; i < 26; i++)
    {
        if (wys[i]%2)
            il++;
    }

    vector<char>res;

    if (il > 1)
    {
        cout << "NO SOLUTION";
    }
    else if (il == 1)
    {
        char t;

        for (int i = 0; i < 26; i++)
        {
            if (wys[i]%2)
            {
                t = i + 'A';
                continue;
            }

            for (int j = 0; j < wys[i]/2; j++)
            {
                res.push_back(i+'A');
            }
        }

        for (auto i : res)
            cout << i;
        for (int i = 0; i < wys[t - 'A']; i++)
            cout << t;

        reverse(res.begin(), res.end());

        for (auto i : res)
            cout << i;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < wys[i]/2; j++)
            {
                res.push_back(i+'A');
            }
        }

        for (auto i : res)
            cout << i;

        reverse(res.begin(), res.end());

        for (auto i : res)
            cout << i;
    }


    
}