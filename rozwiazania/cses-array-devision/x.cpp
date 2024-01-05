#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 2e5 + 10;

int n, k;
ll a[MAXN];

ll solve(ll c, ll b)
{
    if (c == b)
        return c;

    ll mid = (c+b)/2, tmp = 0; int l = 1;

    for (int i = 1; i <= n; i++)
    {
        if (tmp + a[i] > mid)
        {
            l++;
            tmp = 0;
            if (l == k+1)
            {
                return solve(mid+1, b);
            }
        }

        tmp += a[i];
    }
    return solve(c, mid);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    ll maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    cout << solve(maxi, 1e16);



}