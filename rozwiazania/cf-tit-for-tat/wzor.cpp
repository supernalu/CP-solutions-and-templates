#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;

int t, n, k;

int a[MAXN];

int main()
{
    cin >> t;

    for (int w = 0 ; w < t; w++)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i < n; i++)
        {
            if (a[i] < k)
            {
                k -= a[i];
                a[n] += a[i];
                a[i] = 0;
                
            }
            if (a[i] >= k)
            {
                a[i] -= k;
                a[n] += k;

                break;
            }

            
            

        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}