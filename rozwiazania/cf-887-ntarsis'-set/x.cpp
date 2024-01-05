//!nie działa!!

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n;
long long  k;
long long a[MAXN];

int check(long long  r)
{
    for (int i = n; i > 0; i--)
    {
        r -= min(k, r/a[i]);
    }

    if (r == 1)
        return 0;
    else if (r < 1)
        return -1;
    else
        return 1;
    
}

long long binSearch(long long l, long long r)
{
    if (l == r)
        return l;

    long long mid = (l+r)/2;

    int tmp = check(mid);

    if (tmp != -1)
        return binSearch(l, mid);
    else
        return binSearch(mid+1, r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        cout << binSearch(1, 1e18) << '\n';
        
    }
}