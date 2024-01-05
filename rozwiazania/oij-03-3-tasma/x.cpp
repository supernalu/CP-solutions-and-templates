#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t;

int n;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        bool poss = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            if (a[i] != a[1])
                poss = 1;

        }

        if (!poss)
        {
            cout << "BRAK\n";

            continue;
        }

        if (a[1] != a[n])
        {
            cout << n - 1 << '\n';
            continue;
        }

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[1])
            {
                res = n - i;
                break;
            }
        }

        for (int i = n; i > 0; i--)
        {
            if (a[i] != a[1])
            {
                res = max(res, i - 1);
                break;
            }
        }

        cout << res << '\n';

        
    }
}