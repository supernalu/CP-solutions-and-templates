#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 1e5 + 10;

int t, n, m;

vector<ll> adj[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            adj[i].clear();


        while (m--)
        {
            ll x, y; cin >> x >> y;

            if (x > y)
                swap(x, y);

            adj[y].push_back(x);
        }


        ll L = 1, res = 0;
        for (ll R = 1; R <= n; R++)
        {   
            for (auto u : adj[R])
            {
                L = max(L, u+1);
            }
            res += (R-L+1);

            //cout << res << '\n';
        }

        cout << res << '\n';

    }
}