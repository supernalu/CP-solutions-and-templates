#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;
long long a[MAXN];
vector<long long> il(MAXN*5, 0);
int last[MAXN*5];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    for (int k = 1; k <= t; k++)
    {
        cin >> n;

        

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            il[a[i]] = 0;
            last[a[i]] = k;
        }
        sort(a+1, a+n+1);
        for (int i = 1; i <= n; i++)
            il[a[i]]++;
        
        long long res = 0;
        for (long long  q = 2; q <= 1000; q++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i]*q*q > MAXN*5)
                    break;
                if (a[i] == a[i-1] || last[a[i]] < k || last[a[i]*q] < k || last[a[i]*q*q] < k)
                    continue;
                res += il[a[i]]*il[a[i]*q]*il[a[i]*q*q];
            }
            //cout << res << ' ';
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i-1])
                continue;
            res += il[a[i]]*(il[a[i]]-1)*(il[a[i]]-2);
        }
        cout << res << '\n';

    }
}