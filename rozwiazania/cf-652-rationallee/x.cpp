#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

bool cmp (long long a , long long  b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;

    cin >> t;

    while (t--)
    {
        long long a[MAXN];
        int n;

        cin >> n;

        int h;

        cin >> h;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        sort(a+1, a+n+1);

        int k = n, il = 0;

        long long res = 0;

        
        vector<long long>c;

        for (int i = 0; i < h; i++)
        {
            long long b;

            cin >> b;

            if (b == 1)
            {
                res += 2*a[k];
                k--;
            }
            else
            {
                il++;
                c.push_back(b);

            }

        }

        sort(c.begin(), c.end(), cmp);

        for (int i = 1; i <= il; i++)
        {
            res += a[k+1-i];
        }

        int u = 1;

        for (auto i : c)
        {
            res += a[u];

            u += (i-1);
        }

        cout << res << '\n';
    }
}