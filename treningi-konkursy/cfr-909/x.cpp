#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
long long a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        map<int, long long> m;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            m[a[i]] = 0; 
        }
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= n; i++)
            m[a[i]]++;
        long long res = 0;
        for (auto i : m)
        {
            long long tmp = i.second;
            res += tmp*(tmp-1)/2;
        }
        long long suf1 = 0, suf2 = 0;
        for (int i = n; i > 0; i--)
        {
            if (a[i] == 1)
            {
                res += suf2;
                suf1++;
            }
            if (a[i] == 2)
            {
                res += suf1;
                suf2++;
            }
        }
        cout << res << '\n';
        
    }
}