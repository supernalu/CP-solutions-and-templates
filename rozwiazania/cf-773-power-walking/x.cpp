#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

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

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        int il = 0;

        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[i-1])
                il++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (i <= il)
            {
                cout << il << ' ';
            }
            else
            {
                cout << i << ' ';
            }
        }

        cout << endl;

    }
}