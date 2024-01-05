#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

int t;
ll l, r;
ll power[21];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    power[0] = 1;
    for (int i = 1; i <= 20; i++)
        power[i] = power[i-1]*2;

    cin >> t;

    while (t--)
    {
        cin >> l >> r;


        ll res;
        for (int i = 0; i <= 20; i++)
        {
            if (l*power[i] > r)
            {
                res = i;
                break;
            }
        }
        cout << res << ' ';

        ll combi = 0;
        if (res == 0)
            combi  = 1;

        ll tmp;

        if (res  > 0)
        {
        tmp = r/power[res-1];

        //cout << tmp << ' ';

        combi += tmp-l+1;
        }

        if (res > 1)
        {
            tmp = r/(power[res-2]*3);

            //cout << tmp << ' ';

            if (tmp >= l)
            {
                ll tmp2 = ((tmp-l+1)*(res-1))%MOD;   
                //cout << tmp2 << ' ';  
                combi += tmp2;       
                combi %= MOD;
            }
        }
        cout << combi << '\n';
    }
}