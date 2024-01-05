#include <bits/stdc++.h>

using namespace std;

constexpr long long INF = 1e18 + 10;

int t;

long long n, x, y, d;

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> t;

    while (t--)
    {

        cin >> n >> x >> y >> d;

        long long res = INF;

        if (x%d == y%d)
        {
            res = min(res, (max(x, y) - min(x, y))/d);
        }
        if (y%d == 1)
        {
            double tmp = ((double)x - 1)/(double)d;


            res = min(res, (y - 1)/d + (long long)ceil(tmp));
        }
        if (y%d == n%d)
        {
            double tmp = ((double)n - (double)x)/(double)d;

            res = min(res, (n - y)/d + (long long)ceil(tmp));
        }

        if (res == INF)
            cout << -1 << '\n';
        else
            cout << res << '\n';

    }
}