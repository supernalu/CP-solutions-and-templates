#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 5e5 + 10;

int n;
ll a[MAXN];
multiset<ll> s;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;

    ll sum = 0;
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (a[i] < 0)
            s.insert(a[i]);

        sum += a[i];

        if (sum < 0)
        {
            ll tmp = *(s.begin());
            s.erase(s.begin());

            sum += -2*tmp;
            res++;
        }
    }

    cout << res;
}
