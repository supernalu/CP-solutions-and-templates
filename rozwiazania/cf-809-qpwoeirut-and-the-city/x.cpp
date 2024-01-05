#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t, n;
long long h[MAXN];

long long pref[MAXN], suf[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> h[i];

        pref[0] = 0;

        suf[0] = 0;

        int m = (n+1)/2 - 1;

        int k = 1;

        long long ZERO = 0;

        for (int i = 2; i < n; i += 2)
        {
            pref[k] = pref[k-1] + max((max(h[i-1], h[i+1]) - h[i] + 1), ZERO);
            k++;
        }

        k = 1;

        for (int i = n-1; i > 1; i -= 2)
        {
            suf[k] = suf[k-1] + max((max(h[i-1], h[i+1]) - h[i] + 1), ZERO);
            k++;
        }

        long long res = 1e18;



        for (int i = 0; i <= m; i++)
        {
            //cout << pref[i] << " " << suf[m-i] << '\n';

            res = min({res, suf[i] + pref[m-i], suf[m-i] + pref[i]});
        }

        cout << res << '\n';

    }
}