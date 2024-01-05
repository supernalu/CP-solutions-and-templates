#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

int a[MAXN];

int pref[MAXN];

int suf[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    pref[1] = 1;

    int res = 1;

    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i-1])
            pref[i] = pref[i-1]+1;    
        else
            pref[i] = 1;

        res = max(res, pref[i]);
    }

    suf[n] = 1;

    for (int i = n-1; i > 0; i--)
    {
        if (a[i] < a[i+1])
            suf[i] = suf[i+1]+1;    
        else
            suf[i] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        if (a[i-1] < a[i+1])
        {
            res = max(res, pref[i-1] + suf[i+1]);
        }
    }

    cout << res;

}   