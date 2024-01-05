#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;

int n, m;
int o[MAXN], p[MAXN];
int res[MAXN];
int il[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> o[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        res[i] = 1e9;
    }

    int h = 1;
    int t; cin >> t;
    if (m <= 1000 &&  t <= 1000) {
    while (t--)
    {
        int l, r, a; cin >> l >> r >> a;
        r--;
        il[o[l-1]] += a;

        if (il[o[l-1]] >= p[o[l-1]])
            res[o[l-1]] = min(res[o[l-1]], h);

        for (int i = l%m; i != (r+1)%m; i = (i+1)%m)
        {
            //cout << i << ' ';
            il[o[i]] += a;

            if (il[o[i]] >= p[o[i]])
                res[o[i]] = min(res[o[i]], h); 
        }
        h++;
        //cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        if (res[i] == 1e9)
            cout << "NIE\n";
        else
            cout << res[i] << '\n';
    }

    }


}