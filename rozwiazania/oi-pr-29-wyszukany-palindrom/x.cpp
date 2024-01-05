#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int z, n;

string s;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> z;

    while (z--)
    {
        cin >> n;

        cin >> s;

        int res = 0;

        string t = "", m = "";

        for (int i = 0; i <= n/2; i++)
        {
            if (i > n - i - 1)
            {
                if (t.size() != 0)
                    res++;

                break;
            }
            else if (i == n-i-1)
            {
                res++;
                continue;
            }

            t = t + s[i];

            m = s[n-i-1] + m;
            
            if (t == m)
            {
                t = "";

                m = "";

                res += 2;
            }

        }

        cout << res << '\n';
    }
}