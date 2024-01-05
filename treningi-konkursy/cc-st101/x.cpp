#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string s, k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> s >> k;
        int res = 1e9 + 10;
        for (int st = 0; st+m-1 < n; st++)
        {
            int tmp = 0;
            for (int i = st; i-st < m; i++)
            {
                int act = i-st;
                tmp += (10+k[act]-s[i])%10;
            }
            res = max(res, tmp);
        }
        cout << res << '\n';
    }
        
}