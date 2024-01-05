#include <bits/stdc++.h>

#define ll long long

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t;

int n;

ll a[MAXN];


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

            a[i] += a[i-1];
        }

        ll mini = 0;

        ll res = 0;

        for (int i = 1; i < n; i++)
        {
            mini = min(mini, a[i]);

            res = max(res, a[i] - mini);
        }

        for (int i = 1; i < n; i++)
        {
            res = max(res, a[n] - a[i]);
        }

        if (res >= a[n])
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }

        //cout << (res>a[n]) ? "NO\n" : "YES\n";
    }
}