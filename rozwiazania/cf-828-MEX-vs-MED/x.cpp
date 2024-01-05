#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr int MAXN = 2e5 + 10;
ll t, n, p[MAXN], id[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
            id[p[i]] = i;
        }
        ll maxBeg = id[0], minEnd = id[0];
        int act = 0;
        ll res = 1;
        for (int dl = 2; dl <= n; dl++)
        {
            if (dl%2)
            {
                act++;
                minEnd = max(minEnd, id[act]);
                maxBeg = min(maxBeg, id[act]);
            }
            ll base = minEnd-maxBeg+1;
            if (base > dl)
                continue;
            ll rest = dl-base;
            ll minBeg = max(1ll, maxBeg-rest), maxEnd = min(n, minEnd+rest); 
            res += min({maxBeg-minBeg+1, maxEnd-minEnd+1, n-dl+1});
            //cout << base << ' ' << rest << ' ' << minBeg << ' ' << maxBeg << ' ' << minEnd << ' ' << maxEnd << ' ' << res << '\n';
        }
        cout << res << '\n';
    }
}