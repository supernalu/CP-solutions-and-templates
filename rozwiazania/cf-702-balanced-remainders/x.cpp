#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e4 + 10;

int t;

int n;

int a[MAXN];

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        int il = n/3;

        int c[3];

        for (int i = 0;  i < 3; i++)
        {
            c[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            c[a[i]%3]++;
        }

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (c[a[i]%3] > il)
            {
                c[a[i]%3]--;

                for (int j = a[i]%3; j < a[i]%3 + 3; j++)
                {
                    if (c[j%3] < il)
                    {
                        //cout << j%3 << ' ';

                        c[j%3]++;
                        break;
                    }
                    res++;
                }
            }
            //cout << res << ' ';
        }
        cout << res << endl;

        
    }
}