#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 110;
constexpr int PSIZE = 25;

int t, n;
long long primes[PSIZE] = {2,	3,	5,	7,	11,	13,	17,	19,	23,	29, 31,	37,	41,	43,	47,	53,	59,	61,	67,	71, 73,	79,	83,	89,	97};
bool poss[30][100];
long long a[MAXN];
long long b[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1;  i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < PSIZE; i++)
            for (int j = 0; j < primes[i]; j++)
                poss[i][j] = 1;
        bool stop = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                b[i][j] = abs(a[i]-a[j]);
                if (b[i][j] == 0)
                {
                    stop = 1;
                    break;
                }
            }
        }
        if (stop)
        {
            cout << "NO\n";
            continue;
        }

        for (int p = 0; p < PSIZE; p++)
        {
            int prime = primes[p];
            //cout << prime << ' ';
            
            for (int i = 1; i < n; i++)
            {
                bool is = 0;
                for (int j = i+1; j <= n; j++)
                {
                    if (b[i][j]%prime == 0)
                    {
                        is = 1;
                        break;
                    }
                }
                if (is)
                {
                    //cout << (prime-a[i]%prime)%prime << ' ';
                    poss[p][(prime-a[i]%prime)%prime] = 0;
                }
                
            }
            //cout << '\n';
        }
    

        bool res = 1;
        for (int i = 0; i < PSIZE; i++)
        {
            bool tmp = 0;
            for (int j = 0; j < primes[i]; j++)
            {
                tmp = tmp or poss[i][j];
                //cout << poss[i][j] << ' ';
            }
            res = res and tmp;    
            //cout << res << '\n';
        }
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}