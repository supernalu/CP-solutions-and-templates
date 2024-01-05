#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

int n;

int a[MAXN];

int id[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    a[1] = a[2] = 1e9 + 10;

    while(t--)
    {
        cin >> n;

        int pref[MAXN];

        int suf[MAXN];

        a[n+3] = a[n+4] = 1e9 + 10;

        for (int i = 3; i <= n+2; i++)
        {
            cin >> a[i];
        }

        pref[0] = 1e9 + 10;

        suf[n+5] = 1e9 + 10;

        for (int i = )

        



    }
}