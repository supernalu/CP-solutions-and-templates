#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e3 + 10;

int n;

bool a[MAXN][MAXN];

vector<int> t(MAXN, 0);

int res = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        int h = 1;

        for (int j = i; j <= n; j++)
        {
            int tmp = 0;

            for (int k = 1; k <= n; k++)
            {
                t[k] += a[k][j];

                tmp++;

                if (t[k] != 0)
                    tmp = 0;

                res = max(res, tmp*h);
            }

            h++;
        }

        t.assign(MAXN, 0);
    }

    cout << res;
        
    


}