#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5 + 10;
int t, n;
ll a[MAXN], b[MAXN], product;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int res = 1; 
        ll gc = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            product = a[i]*b[i];
            gc = b[i]*gc/__gcd(gc, b[i]);
            if (product%gc != 0 || gc <= 0)
            {
                res++;
                gc = 1;
            }
        }
        cout << res << '\n';

    }
}