#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 3e5 + 10;

int n, q;

pair<ll, ll> router[MAXN];
ll power[MAXN];
int id[MAXN];

ll l[MAXN];
ll r[MAXN];


bool cmp1(int a, int b)
{
    return router[a] < router[b];
}


int bin1 (int a, int b, ll val)
{
    int mid = (a+b+1)/2;
    //cout << mid << '\n';
    if (a == b)
        return a;
    if (router[id[mid]].first <= val)
        return bin1(mid, b, val);
    return bin1(a, mid-1, val);
}

int bin2 (int a, int b, ll val)
{
    int mid = (a+b)/2;
    //cout << mid << '\n';
    if (a == b)
        return a;
    if (router[id[mid]].first >= val)
        return bin2(a, mid, val);
    return bin2(mid+1, b, val);
}


void solve1()
{
    while (q--)
    {
        ll a, b, maxi = 0; cin >> a >> b;

        for (int i = 1; i <= n; i++)
        {
            maxi = max(maxi, power[i] - max(abs(router[i].first-a), abs(router[i].second-b)));
        }
        cout << maxi << '\n';
    }
}

void solve2()
{
    sort(id, id + n + 2, cmp1);

    l[0] = power[id[1]];
    for (int i = 1; i <= n; i++)
    {
        l[i] = max(power[id[i]], l[i-1]-(router[id[i]].first-router[id[i-1]].first));
        //cout << l[i] << ' ';
    }
    //cout << '\n';
    r[n+1] = power[id[n]];
    for (int i = n; i > 0; i--)
    {
        r[i] = max(power[id[i]], r[i+1] -(router[id[i+1]].first-router[id[i]].first));
        //cout << r[i] << ' ';
    }
    //cout << '\n';

   

    while (q--)
    {
        ll a,  b; cin >> a >> b;

        //cout << bin1(0, n+1, a) << ' ' << bin2(0, n+1, a) << ' ' << bin3(0, n+1, b) << ' ' << bin4(0, n+1, b) << '\n';

        //cout << l[id[bin1(0, n+1, a)]] - a + router[id[bin1(0, n+1, a)]].first << ' ' << r[id[bin2(0, n+1, a)]] - router[id[bin2(0, n+1, a)]].first + a << '\n';
        //cout << d[id2[bin1(0, n+1, b)]] - b + router[id2[bin1(0, n+1, b)]].second << ' ' << u[id2[bin4(0, n+1, b)]] - router[id2[bin4(0, n+1, b)]].second + b << '\n';

        cout << max(0ll, max(l[id[bin1(0, n+1, a)]] - a + router[id[bin1(0, n+1, a)]].first, r[id[bin2(0, n+1, a)]] - router[id[bin2(0, n+1, a)]].first + a)) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    id[0] = 0; id[n+1] = n+1; 
    router[0] = {-1e18-10, -1e18-10};
    router[n+1] = {1e18+10, 1e18+10};

    for (int i = 1; i <= n; i++)
    {
        cin >> router[i].first >> router[i].second >> power[i];
        id[i] = i;
        
    }

    if (n <= 5000 && q <= 5000)
        solve1();
    else 
        solve2();

}