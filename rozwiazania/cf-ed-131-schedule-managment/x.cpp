#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t, n, m;

long long a[MAXN];

int solve()
{
    int L = 0, R = 4e5 + 20;

    int res = 4e5 + 40;

    while (L <= R)
    {
        int mid = (L+R)/2;
        long long zapas = 0;
        bool good_enough = 1;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] < mid)
                zapas += (mid-a[i])/2;     
            else
            {
                zapas -= (a[i]-mid);

                if (zapas < 0)
                {
                    good_enough = 0;
                    break;
                }
            }
        }

        if (good_enough)
        {
            res = min(res, mid);
            R = mid - 1;
        }
        else
            L = mid+1;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
            a[i] = 0;

        for (int i = 1; i <= m; i++)
        {
            int b;
            cin >> b;

            a[b]++;
        }

        sort(a+1, a+n+1);

        cout << solve() << '\n';
    }
}