#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;

int t, n;
int a[MAXN];
int maxiPref[MAXN], maxiSuf[MAXN];
//int id[MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n;

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i]-=i;
            maxiPref[i] = max(maxiPref[i-1], a[i]+2*i);
            
        }

        maxiSuf[n+1] = -1e9;
        for (int i = n; i > 0; i--)
            maxiSuf[i] = max(maxiSuf[i+1], a[i]);
        

        for (int i = 2; i < n; i++)
        {
            //cout << maxiPref[i-1] << ' '  << maxiSuf[i+1] << '\n';
            res = max(res, a[i]+ i + maxiPref[i-1]+maxiSuf[i+1]);
        }
        
        cout << res << '\n';


    }
}