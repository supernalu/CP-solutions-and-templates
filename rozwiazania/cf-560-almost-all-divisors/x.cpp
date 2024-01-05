#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 310;

int t, n; 
ll d[MAXN];

vector<ll> dive;

void divisors(ll q)
{
    dive.clear();
    for (ll i = 1; i*i <= q; i++)
    {
        if (q%i != 0)
            continue;

        dive.push_back(i);

        if (q/i != i)
            dive.push_back(q/i); 
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> d[i];
        }
        sort(d + 1, d + n + 1);
        ll res = d[n]*d[1];

        divisors(res);

        bool poss = 1;
        if (dive.size()-2 != n)
            poss = 0;
        for (int i = 1; i <= n; i++)
        {
            if (res%d[i] != 0)
                poss = 0;
        }

        if (poss)
            cout << res << '\n';
        else
            cout << -1 << '\n';
    }
}