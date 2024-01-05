#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
constexpr int SQRT = 1e3 + 20;
int t, n, q;
long long a[MAXN];
int wh[MAXN];
int mini[SQRT], maxi[SQRT];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        cin >> n;
        int sq = sqrt(n+1);
        for (int i = 1; i <= sq; i++)
            
        long long res = 0;
        int it = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i%sq)
                it++;
            wh[i] = it;
        }
        for (int i = 1; i <= n; i++)
        {
        }
        cin >> q;

        
        cout << "Case #" << Case << ": " << res << '\n';
    }
}