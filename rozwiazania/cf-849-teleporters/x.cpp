#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 2e5 + 10;

int t, n;
ll C;
ll cost[MAXN];
pair<ll, int> realCost[MAXN];
ll SumPref[MAXN];

int binsearch(int l, int r, ll var)
{
    if (l == r)
        return l;

    int mid = (l+r+1)/2;

    if (SumPref[mid] <= var)
        return binsearch(mid, r, var);
    else
        return binsearch(l, mid-1, var);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> C; SumPref[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int a; cin >> a;
            cost[i] = a;
            realCost[i].first = min(i, n-i+1) + a;
            realCost[i].second = i;
        }
        sort(realCost + 1, realCost + n + 1);

        for (int i = 1; i <= n; i++)
        {
            SumPref[i] = SumPref[i-1] + realCost[i].first;
            //cout << SumPref[i] << ' ';
        }

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            int id = realCost[i].second;
            ll c = C;
            
            if (c - cost[id]-id < 0)
                continue;
            int tmp = 1;
            c -= (cost[id]+id);
            

            if (SumPref[i-1] > c)
            {
                int x = binsearch(0, i-1, c);
                tmp += x;
                res = max(res, tmp);
                continue;
            }

            c-= SumPref[i-1];
            tmp += i-1;
            int x = binsearch(i, n, c + SumPref[i]);
            tmp += (x-i); 
            res = max(res, tmp);
        }

        cout << res << '\n';
    }
}