#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int LEAVES = 1 << 18;

ll a[LEAVES];
vector<ll> maximumRangeQuery(2*LEAVES, 0);
vector<int> l(2*LEAVES);
vector<int>r(2*LEAVES);
vector<ll>lazy(2*LEAVES, 0);
int n, q;

void initiation()
{
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        l[i] = i - LEAVES;
        r[i] = i - LEAVES;
    }
    for (int i = LEAVES - 1; i > 0; i--)
    {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
        maximumRangeQuery[i] = max(maximumRangeQuery[2*i], maximumRangeQuery[2*i+1]);
    }
}

void lazyPropagtion(int v)
{
    if (lazy[v] == 0)
        return;

    maximumRangeQuery[v] += lazy[v];
    if(v < LEAVES)
    {
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
    } 
    lazy[v] = 0;
}

ll query(int a, int b, int v)
{
    if (l[v] > b || r[v] < a)
        return -1e18;
    lazyPropagtion(v);
    if (l[v] >= a && r[v] <= b)
        return maximumRangeQuery[v];
    return max(query(a, b, 2*v), query(a, b, 2*v+1));
}

void update(int a, int b, int v, ll val)
{
    if (l[v] > b || r[v] < a)
        return;
    lazyPropagtion(v);
    if (l[v] >= a && r[v] <= b)
    {
        lazy[v] += val;
        lazyPropagtion(v);
        return;
    }  
    update(a, b, 2*v, val);
    update(a, b, 2*v+1, val);
    maximumRangeQuery[v] = max(maximumRangeQuery[2*v], maximumRangeQuery[2*v+1]);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    maximumRangeQuery[LEAVES] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maximumRangeQuery[LEAVES+i] = maximumRangeQuery[LEAVES+i-1]+a[i];
        //cout << maximumRangeQuery[LEAVES+i] << ' ';
    }
    initiation();

    while (q--)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int k; ll u; cin >> k >> u;
            update(k, n, 1, u - a[k]);
            a[k] = u;
        }
        else
        {
            int a, b; cin >> a >> b;
            cout << max(0ll, query(a, b, 1) - query(a-1, a-1, 1)) << '\n';
        }
    }
}