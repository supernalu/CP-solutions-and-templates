#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int t, n, m, k;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }

        int ilMax = n*m-3;

        vector<bool> been(k+1, 0);

        int act = k;
        int ilAct = 0;

        bool res = 1;

        for (int i = 1; i <= k; i++)
        {
            been[a[i]] = 1;
            ilAct++;

            if (ilAct > ilMax)
                res = 0;

            while (been[act])
            {
                act--;
                ilAct--;
            }

            //cout << ilAct << ' ';
        }

        if (res)
            cout << "YA\n";
        else
            cout << "TIDAK\n";
    }
}