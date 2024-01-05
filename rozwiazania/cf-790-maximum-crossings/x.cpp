#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t, n;

int a[MAXN];
int pref[MAXN];


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
        }

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                if (a[i] <= a[j] && i > j || a[i] >= a[j] && i < j)
                    res++;
            }
        }

        cout << res << '\n';
    }
}