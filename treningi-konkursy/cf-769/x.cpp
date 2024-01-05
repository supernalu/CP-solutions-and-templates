#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

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

        int pow = 1;

        while (2*pow < n)
        {
            pow *= 2;
        }

        int tmp = pow-1;

        while (tmp >= 0)
        {
            cout << tmp << ' ';

            tmp--;
        }

        for (int i = pow; i < n; i++)
        {
            cout << i << ' ';
        }

        cout << '\n';

    }
}