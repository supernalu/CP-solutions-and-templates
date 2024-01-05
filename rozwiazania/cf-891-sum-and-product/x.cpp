#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5 + 10;
int t, n, q;
ll a[MAXN];
ll binSearch(ll l, ll r, ll k)
{
    if (l == r)
        return l;
    int mid = (l+r)/2;
    if (a[mid] >= k)
        return binSearch(l, mid, k);
    else
        return binSearch(mid+1, r, k);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        a[n+1] = a[n]+1;
        a[0] = a[1]-1;
        cin >> q;
        while (q--)
        {
            ll x, y; cin >> x >> y;
            ll delta=x*x-4*y, sDel;
            if (delta < 0)
            {
                cout << "0 ";
                continue;
            }
            sDel = sqrt(delta);
            if (sDel*sDel != delta)
            {
                cout << "0 ";
                continue;
            }
            ll r1 = (x-sDel)/2, r2 = (x+sDel)/2;
            //cout << r1 << ' ' << r2 << '\n';
            ll il1 = binSearch(0, n+1, r1+1)-binSearch(0, n+1, r1), il2 = binSearch(0, n+1, r2+1)-binSearch(0, n+1, r2);
            if (r1 != r2)
                cout << il1*il2 << ' ';
            else
                cout << (il1*(il2-1))/2 << ' ';
        }
        cout << '\n';
    }
}