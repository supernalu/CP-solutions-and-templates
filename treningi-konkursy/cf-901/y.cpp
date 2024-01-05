#include <bits/stdc++.h>
using namespace std;
long long t, n, m, orgM;
long long power[32];
int main()
{
    power[0] = 1;
    for (long long i = 1; i <= 30; i++)
        power[i] = 2*power[i-1];
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        orgM = m;
        long long k = n/m;
        n -= k*m;
        //cout << n << ' ';
        if (n == 0)
        {
            cout << "0\n";
            continue;
        } 
        k = __gcd(n, m);
        long long orgN = n;
        n /= k;
        m /= k;  
        bool poss = 0;
        for (int i = 0; i <= 30; i++)
            if (m == power[i])
            {
                //cout << i << ' ';
                poss = 1;
                break;
            }
        if (!poss)
        {
            cout << "-1\n";
            continue;
        }
        long long res = 0;
        long long il = orgN;

        for (long long i = 1; power[i] <= m; i++)
        {
            //cout << il << ' ';
            res += il;
            //cout << res << ' ';
            il *= 2;
            if (n >= m/power[i])
            {
                n -= m/power[i];
                il -= orgM;    
            }
        }
        cout << res << '\n';
    }
}