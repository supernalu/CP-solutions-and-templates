#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

int f[MAXN], w[MAXN];

int il[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }

    int max_res = 0;

    for (int i = 1; i <= n; i++)
    {
        int res = 0;

        for (int j = i; j <= n; j++)
        {
            il[f[j]]++;

            if (il[f[j]] == 1)
            {
                res += w[f[j]];

                max_res = max(max_res, res);
            }
            else if (il[f[j]] == 2)
            {
                res -= w[f[j]];
            }
        }

        for (int j = 1; j <= m; j++)
        {
            il[j] = 0;
        }
    }

    cout << max_res;
}