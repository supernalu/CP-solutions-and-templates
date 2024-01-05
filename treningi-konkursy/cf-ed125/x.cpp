#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

long long n;

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        cin >> s;

        int il = 0, res = 0;



        for (int i = 0; i < n; i++)
        {
            //cout << i << ' ';

            if (s.substr(i, 2) == "()")
            {
                il++;
                i++;
                continue;
            } 
            else
            {
                char bomb = s[i];

                int j;

                for ( j = i + 1; j < n; j++)
                {
                    if (s[j] == bomb)
                    {
                        il++;
                        i = j;
                        break;
                    }
                }

                if (j == n)
                {
                    res = n - i;
                    break;
                }

            }
        }

        cout << il << ' ' << res << '\n';


        
    }
}