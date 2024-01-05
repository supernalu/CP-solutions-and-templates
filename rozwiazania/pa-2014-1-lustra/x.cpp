#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int t, n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int miniw = 1e9 + 10, maxiw = 0, minih = 1e9 + 10, maxih = 0;

        int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i] >> d[i];

            if (a[i] < miniw)
                miniw = a[i];
            if (b[i] > maxiw)
                maxiw = b[i];
            if (c[i] < minih)
                minih = c[i];
            if (d[i] > maxih)
                maxih = d[i];
        }

        bool res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] == miniw && b[i] == maxiw && c[i] == minih && d[i] == maxih)
            {
                res = 1;
                cout << "TAK\n";
                break;
            }
        }


        if (!res)
        cout << "NIE\n";

        

    }
}