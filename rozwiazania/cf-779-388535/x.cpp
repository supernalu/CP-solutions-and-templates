#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 131072;
int t, l, r;
int pref[MAXN][17];
int il[17];
int power[17];
void add(int a)
{
    for (int i = 16; i >= 0; i--)
    {
        if(a >= power[i])
        {
            il[i]++;
            a-=power[i];
        }
    }
}
int main()
{
    power[0] = 1;
    for (int i = 1; i < 17; i++)
    {
        power[i] = 2*power[i-1];
        pref[0][i] = 0;
    }
    for (int i = 1; i < MAXN; i++)
    {
        int tmp = i;
        for (int j = 16; j >= 0; j--)
        {
            if (tmp >= power[j])
            {
                pref[i][j] = pref[i-1][j]+1;
                tmp -= power[j];
            }
            else
                pref[i][j] = pref[i-1][j];
        }
    }
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        int n = r-l+1;
        for (int i = 0; i < 17; i++)
            il[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int a; cin >> a;
            add(a);
        }
        int res = 0;
        for (int i = 0; i < 17; i++)
        {
            //cout << il[i] << ' ' << pref[r][i] << '\n';
            if (il[i] != pref[r][i]-pref[max(l-1, 0)][i])
                res += power[i];
        }
        cout << res << '\n';
    }
}