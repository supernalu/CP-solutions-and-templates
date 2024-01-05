#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t, n, k;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int streak = 0, res = 0;

        for (int i = 1; i < n; i++)
        {
            if (a[i] >= 2*a[i+1])
            {
                streak = 0;
                continue;
            }

            streak++;

            if (streak >= k)
                res++;
        }

        cout << res << '\n';
    }
}