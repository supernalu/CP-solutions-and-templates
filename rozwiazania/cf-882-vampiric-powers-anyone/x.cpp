#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int t, n;
short a[MAXN], pref[MAXN];

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
            pref[i] = pref[i-1] xor a[i];
        }

        for (int i = 0; i < 4; i++)
        {
            a[n+1+i] = pref[n+i];
            pref[n+1+i] = pref[n+i]|a[n+i+1];
        }

        short maxi = 0;
        for (int i = 1; i < n+4; i++)
            maxi = max(maxi, a[i]);
        cout << maxi << '\n';
        
    }
}