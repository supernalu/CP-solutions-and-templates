#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s;

    ll u = 0, v = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '-')
            u++;
        else
            v++;
    }

    int q; cin >> q;

    while (q--)
    {
        ll a, b; cin >> a >> b;

        if (b < a)
            swap(a, b);

        if (b == a)
        {
            if (u != v)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }

        if ((a*abs(u-v))%(b-a) != 0)
        {
            cout << "NO\n";
            continue;
        }

        ll r = (a*abs(u-v))/(b-a);
        //cout << r;

        if (min(u,v) >= r)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}