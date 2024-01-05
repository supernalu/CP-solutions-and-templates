#include <bits/stdc++.h>

using namespace std;

int t;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        string s;

        cin >> s;

        cout << s << ' ';

        if (s == "1" || s == "4")
        {
            cout << '\n';
            continue;
        }

        long long n = 0;

        for (int i = 0; i < s.size(); i++)
        {
            n += (s[i]-48)*(s[i]-48);
        }

        while (n != 1 && n != 4)
        {
            cout << n << ' ';

            string v = to_string(n);

            n = 0;

            for (int i = 0; i < v.size(); i++)
            {
                n += (v[i]-48)*(v[i]-48);
            }        
        }

        cout << n << '\n';
    }
}