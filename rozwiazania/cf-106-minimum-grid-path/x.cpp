#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5;

int t;

int n;

long long a[MAXN][2];



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 2; i <= n+1; i++)
        {
            cin >> a[i/2][i%2];
        }

        if ((n+1)%2 == 0)
        {
            a[(n+1)/2][1] = 0;
        }



        long long mini[MAXN][2];

        long long suma[MAXN][2];

        mini[0][0] = mini[0][1] = 1e9;

        suma[0][0] = suma[0][1] = 0;

        for (int i = 1; i <= (n+1)/2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                mini[i][j] = min(mini[i-1][j], a[i][j]);

                suma[i][j] = suma[i-1][j] + a[i][j];
            }
        }

        long long res = 1e18;

        long long tmp = 0;

        for (int i = 1; i <= (n+1)/2; i++)
        {

            if (i > 1)
            {
                if (a[i][1] == 0)
                {
                    tmp = suma[i][0] + mini[i][0]*(n-i) + suma[i-1][1] + mini[i-1][1]*(n-i+1);

                    //cout << suma[i][0] << ' ' << mini[i][0]*(n-i) << ' ' << suma[i-1][1] << ' ' <<  mini[i-1][1]*(n-i+1) << '\n';
                }
                else
                tmp = min(suma[i][0] + mini[i][0]*(n-i) + suma[i][1] + mini[i][1]*(n-i), suma[i][0] + mini[i][0]*(n-i) + suma[i-1][1] + mini[i-1][1]*(n-i+1));
            }
            else
                 tmp = suma[i][0] + mini[i][0]*(n-i) + suma[i][1] + mini[i][1]*(n-i);
            //cout << tmp << ' ';

            res = min(res, tmp);
        }

        cout << res << '\n';
        
        
    }
}