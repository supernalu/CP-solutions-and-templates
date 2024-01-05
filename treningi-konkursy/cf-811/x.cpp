#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;
constexpr int INF = 1e9 + 10;

int t, n;

int a[MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;


    while(t--)
    {
        cin >> n;
        
        int mini = INF, maxi = 0;

        bool poss = 1;

        bool wys = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            if ((a[i]%10)%2 == 1)
            {
                a[i] += (a[i]%10);
            }

            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);

            if (a[i]%10 == 0)
            {

                wys = 1;
                continue;
            }

            poss = 0;
        }

        if (maxi == mini)
        {
            cout << "YES\n";

            continue;
        }

        if (wys)
        {
            cout << "NO\n";
            continue;
        }

        bool res = 1;


        for (int i = 1; i <= n; i++)
        {
            if (a[i]%10 == 6 && (a[i]/10)%2 == 1 || a[i]%10 != 6 && (a[i]/10)%2 == 0)
                continue;

            res = 0;
        }

        if (res)
        {
            cout << "YES\n";
            continue;
        }

        res = 1;

        for (int i = 1; i <= n; i++)
        {
            if (a[i]%10 == 6 && (a[i]/10)%2 == 0 || a[i]%10 != 6 && (a[i]/10)%2 == 1)
                continue;

            res = 0;
        }

        if (res)
        {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    
    }
}