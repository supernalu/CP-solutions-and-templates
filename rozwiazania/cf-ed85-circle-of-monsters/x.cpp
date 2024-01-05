//*Do przeanalizowania dokładniejszego :)))

#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;

int t, n;

pair<long long, long long> mon[MAXN];

long long a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            //long long a, b;

            cin >> mon[i].first >> mon[i].second;

            //mon[i] = {a, b};
        }

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            int j = (i+1)%n;

            a[i] = max(mon[j].first - mon[i].second, 0ll);

            //cout << a[i] << ' '; 

            sum += a[i];
        }

        long long res = 1e18 + 20;

        for (int i = 0; i < n; i++)
        {
            //int j = (i+1)%n;

            //cout << sum << ' ' <<  a[i] << ' ' <<  mon[(i+1)%n].first << '\n';

            res = min(res, sum - a[i] + mon[(i+1)%n].first);

            //cout << res << ' ';
        }

        cout << res << '\n';

    }
}