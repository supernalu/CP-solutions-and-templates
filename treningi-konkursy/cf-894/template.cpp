#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n;
ll a[MAXN];
/*
void binsearch(int l, inr r)
{
    if (l ==r)
        return l;
    int mid = (l+r)/2;
}
*/
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
    }
}
ll tmp = 0;
        ll res = 0;
        for (int i = 1; i <= m; i++)
        {
            if (a[i] <= -d)
            {
                tmp -= d;
                res = max(res, tmp);
                break;
            }
            else
            {
                tmp += a[i];
                s.insert(a[i]); 
            }
            res = max(res, tmp);
            cout << tmp << ' ';
        }
        for (int i = m+1; i <= n; i++)
        {
            if (s.size() < m && a[i] > -d)
            {
                tmp += a[i];
                s.insert(a[i]);
            }
            else if (a[i] >= *(s.begin()))
            {
                tmp -= d;
                tmp += (a[i]-*(s.begin()));
                s.erase(s.begin());
                s.insert(a[i]);
            }
            else
                tmp -= d;
            res = max(res, tmp);
            cout << res << ' ';
        }
        cout << res << '\n';