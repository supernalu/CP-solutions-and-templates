#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int t;

long long n, x;

long long a[MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        map<long long, int> il, il2;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            il[a[i]]++;

            il2[a[i]]++;
        }

        sort(a + 1, a + n + 1);
        
        int tmp1 = n;

        for (int i = 1; i <= n; i++)
        {
            //cout << il[a[i]] << ' ';

            //cout << res << ' ' << il[a[i]] << ' ' << il[a[i]*x] << endl;

            long long q = a[i]*x;

            long long r = min(il[a[i]], il[q]);

            tmp1 -= 2*r;
            il[a[i]] -= r;
            il[q] -= r;

            
        }

        cout << tmp1 << '\n';

    }
}