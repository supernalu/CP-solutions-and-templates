#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    int res = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long x, y, z;

        cin >> x >> y >> z;

        long long f = x*a + y*b + z, e = x*c + y*d + z;

        if (f > 0 && e < 0 || f < 0 && e > 0)
            res++;
    }

    cout << res;
   
}   