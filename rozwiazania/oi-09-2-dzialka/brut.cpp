#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e3 + 10;

int n;

int pref[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> pref[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j];

    int res = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= i; k++)
                for (int h = 1; h <= j; h++)
                {
                    if (pref[i][j] + pref[k-1][h-1] - pref[k-1][j] - pref[i][h-1] == 0)
                    {
                        res = max(res, (i-k+1)*(j-h+1));
                    }
                }

    cout << res;
}