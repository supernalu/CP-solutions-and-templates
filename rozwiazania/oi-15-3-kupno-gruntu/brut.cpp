#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2010;

int n, q;

int a[MAXN][MAXN];

int pref[MAXN][MAXN];

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> q >> n;

    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < i; k++)
            {
                for (int l = 0; l < j; l++)
                {
                    //cout << pref[i][j] + pref[k][l] - pref[i][l] - pref[k][j] << endl;

                    if (pref[i][j] + pref[k][l] - pref[i][l] - pref[k][j] >= q && pref[i][j] + pref[k][l] - pref[i][l] - pref[k][j] <= 2*q)
                    {
                        cout << l + 1 << ' ' <<  k + 1 << ' ' << j << ' ' <<  i;

                        return 0;
                    }
                }
            }
        }
    }

    cout << "NIE";
}