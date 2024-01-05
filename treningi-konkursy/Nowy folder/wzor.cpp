#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 2e5 + 10;
 
int t;
 
int n, k;

long long a[MAXN];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
 
    while (t--)
    {     
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        long long res = 0;

        for (int i = 30; i >= 0; i--)
        {
            int il = 0;

            for (int j = 1; j <= n; j++)
            {
                if (!(a[j] >> i & 1))
                {
                    il++;
                }
            }

            if (il <= k)
                {
                    res += 1 << i;

                    k -= il;
                }
        }

        cout << res << '\n';


    }
}
