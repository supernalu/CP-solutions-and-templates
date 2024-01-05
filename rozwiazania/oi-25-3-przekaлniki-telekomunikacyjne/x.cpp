//{a, b}
#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int MAXN = 3e5 + 10;
constexpr int LEAVES = 1 << 19;

int n, q;
pair<int, int> maszt[MAXN];
vector<pair<ll, ll>> linearFunctionRangeQuery(2*LEAVES, {0, 0});
vector<int> l(2*LEAVES);
vector<int> r(2*LEAVES);
vector<pair<ll, ll>> lazy(2*LEAVES);

void initiation()
{
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        l[i] = i-LEAVES;
        r[i] = i-LEAVES;
    }
    for (int i = LEAVES-1; i > 0; i--)
    {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
    }
}

void lazyPropagation(int v)
{
    if (lazy[v] == {0, 0})
        return;

    if (v < LEAVES)
    {
        ll a = lazy[v].second, b = lazy[v].first;
        lazy[2*v].first += b;
        lazy[2*v].second += a;
        lazy[2*v+1].first += b + a*(r[2*v]-l[2*v]+1);
        lazy[2*v+1].second += a;
    }
    linearFunctionRangeQuery[v].first += lazy[v].first;
    linearFunctionRangeQuery[v].second += lazy[v].second;
    lazy[v] = {0, 0};
}

void update(int left, int right, int v, ll b, ll a)
{
    lazyPropagation(v);

    if (right < l[v] || r[v] < left)
        return;
    if (l[v] <= left && rigt <= r[v])
    {
        lazy[v].first += b;
        lazy[v].second += a;
        lazyPropagation(v);
        return;
    }
    update(left, right, 2*v, b, a); update(left, right, 2*v+1, b + a*(r[2*v]-l[2*v]+1, a));   
}

ll query(int left, int right, int v)
{
    lazyPropagation(v);
    if (right < l[v] || r[v] < left)
        return 0ll;
    if (l[v] <= left && rigt <= r[v])
    {
        return (2*b + (r[v]-l[v]+1)*a)*(r[v]-l[v]+1)/2;
    }
    query(left, right, 2*v); query(left, right, 2*v+1);   
}



int main()
{
    initiation();
    cin >> n >> q;

    while (q--)
    {
        char z; cin >> z;

        if (z == 'P')
        {
            int a, b, c; cin >>a >> b >> c;
        }
        else if (z == 'U')
        {

        }
        else
        {
            int a, b; cin >> a >> b;
            cout << query(a, b, 1);
        }
    }
}