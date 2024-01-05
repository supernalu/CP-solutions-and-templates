#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int t;
int n, q;
unsigned long long a[MAXN];
unsigned long long power[61];
unsigned long long ile[61];
unsigned long long bezzmian[61];
unsigned long long dodatek[61][61];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    power[0] = 1;
    for (int i = 1; i <= 60; i++)
        power[i] = power[i-1]*2;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int k = 0; k < 61; k++)
    {
        //bezzmian[k] = 2*power[60]-1;
        for (int i = 1; i <= n; i++)
        {
            unsigned long long tmp2 = 0;
            unsigned long long tmp = a[i];
            for (int j= 60; j > k; j--)
                if (tmp >= power[j])
                {
                    tmp-=power[j];
                }
            //bezzmian[k] = bezzmian[k]&tmp2;
            if (tmp > power[k])
            {
                //dodatek[k] += tmp-power[k];
                for (int h = 60; h > 0; h--)
                {
                    if (tmp >= power[h])
                    {
                        tmp -= power[h];
                        dodatek[k][h]++;
                    }
                }
            }
            ile[k] += power[k]-tmp;
        }
        if (k < 10)
        cout << ile[k] << ' ';
    }
    
    while (q--)
    {
        unsigned long long res = 0;
        int k; cin >> k;
        for (int i = 60; i >= 0; i--)
        {
            unsigned long long tmp = k;
            if (ile[i] <= tmp)
            {
                tmp -= ile[i];
                for (int j = 0; j < 60; j++)
                    ile[j] -= dodatek[i][j];
                //if (i == 2)
                    //cout << power[i]+ min(tmp/n, power[i]-1) << ' ' << bezzmian[i] << ' ';
                res += power[i];
            }
        }
        cout << res << '\n';
    }


    return 0;
}