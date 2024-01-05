#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n, m, d;
int a[MAXN];
int pref[MAXN];
int suf[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i];
            pref[i] = 0;
            suf[i] = 0;
        }
        suf[0] = 0;
        pref[0] = 1;
        pref[m+1] = 0;
        suf[m+1] = 0;
        a[0] = 1;  
        a[m+1] = n+1;
        for (int i = 1; i <= m+1; i++)
        {
            if (i == 1 && a[i] == 1)
            {
                pref[1] = 1;
                continue;
            }
            pref[i] = pref[i-1]+1+(a[i]-a[i-1]-1)/d;
            if (i == m+1)
                pref[i]--;
        }        
        for (int i = m; i > 0; i--)
        {
            suf[i] = pref[m+1] - pref[i]+1;
        }
        suf[0] = pref[m+1];
        int mini = 1e9 + 10;
        for (int i = 1; i <= m; i++)
        {
            mini = min(mini, pref[i-1]+suf[i+1]+(a[i+1]-a[i-1]-1)/d);
        }
        cout << mini << ' ';
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            if (pref[i-1]+suf[i+1]+(a[i+1]-a[i-1]-1)/d == mini)
                count++;
        }
        cout << count << '\n';
    }
}