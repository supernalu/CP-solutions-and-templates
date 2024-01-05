#include <bits/stdc++.h>

using namespace std;

long long MOD = 998244353;
constexpr int MAXN = 2e5 + 10;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        long long n;
        long long  a[MAXN];

        cin >> n;

        for (int i = 1; i<= n; i++)
        {
            cin >> a[i];
        }

        sort(a+1, a+n+1);

        if (a[n]-a[n-1] >= 2)
        {
            cout << 0 << '\n';
        }
        else if (a[n]-a[n-1] == 1)
        {
            long long j = 0;

            for (int i = n-1; i>0;i--)
            {
                if (a[i] == a[n-1])
                    j++;
                else
                    break;
            }
            

            long long res = j;

            for (long long i = 1; i <= n; i++)
            {
                if (i == j+1)
                    continue;


                res *= i%MOD;
                res %= MOD;
            }

            cout << res << '\n';


        }
        else
        {
            long long  k = 1;

            for (long long i = 1; i <= n; i++)
            {
                k*=i%MOD;
                k%= MOD;
            }

            cout << (k)%MOD << '\n';
        }
    }
}