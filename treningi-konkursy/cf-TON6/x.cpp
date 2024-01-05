#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n, k;
int a[MAXN];
int miniID[MAXN];
int res[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
            res[i] = 0;
        cin >> k;
        a[0] = 1e9+10;
        miniID[n] = n;
        for (int i = n-1; i > 0; i--)
        {
            if (a[i] < a[miniID[i+1]])
                miniID[i] = i;
            else
                miniID[i] = miniID[i+1];
        }
        int lastIle = 1e9+10;
        int act = 0; 
        int oldwh = 0, wh = 1;
        while (wh <= n && k > 0)
        {
            oldwh = wh;
            wh = miniID[wh];
            int ile = min(lastIle, k/(a[wh]-act));
            if (ile == 0)
                break;
            for (int i = oldwh; i <= wh; i++)
            {
                res[i] = ile;
            }
            k -= ile*(a[wh]-act);
            act = a[wh];
            wh++;
            lastIle = ile;
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
}