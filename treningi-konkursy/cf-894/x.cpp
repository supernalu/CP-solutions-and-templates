#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
ll t, n, m, d;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;  
        multiset<ll> s;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];  
            a[i] = max(a[i], 0ll); 
        }
        ll tmp = 0;
        ll res = 0;
        for (int i = 1; i <= m; i++)
        {
            /*
            if (a[i] < 0)
            {
                tmp -= d;
                res = max(res, tmp);
                continue;
            }
            */
            
                tmp -= d;
                tmp += a[i];
                s.insert(a[i]);
                 //cout << s.size() << '\n'; 
            
            res = max(res, tmp);
            //cout << tmp << ' ';
        }
        for (int i = m+1; i <= n; i++)
        {
            tmp -= d;
            //cout << s.size() << ' ';
            if (s.size() < m)
            {
                tmp += a[i];
                s.insert(a[i]);
            }
            else if (a[i] >= *(s.begin()))
            {
                //cout << *(s.begin()) << ' ' << i << '\n'; 
                tmp += (a[i]-*(s.begin()));
                s.erase(s.begin());
                s.insert(a[i]);
            }
            
            res = max(res, tmp);
            //cout << tmp << ' ';
        }
        cout << res << '\n';
    }
}