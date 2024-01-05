#include <bits/stdc++.h>
#define ll long long

using namespace std;

constexpr int LEAVES = 1 << 18;

int n, q;
vector<ll> maximumRangeQueries(2*LEAVES, 0);
vector<int> l(2*LEAVES);
vector<int> r(2*LEAVES);

void initiation()
{
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        l[i] = i - LEAVES;
        r[i] = i - LEAVES;
    }
    for (int i = LEAVES-1; i > 0 ; i--)
    { 
        l[i] = l[2*i];
        r[i] = r[2*i+1];
        maximumRangeQueries[i] = max(maximumRangeQueries[2*i], maximumRangeQueries[2*i+1]);
    }
}

ll query(int a, int b, int v)
{
    if (l[v] > b || r[v] < a)
        return 0;
    if (l[v] >= a && r[v] <= b)
        return maximumRangeQueries[v];
    return max(query(a, b, 2*v), query(a, b, 2*v+1));
}

void update(int a, int b)
{
    a += LEAVES;
    maximumRangeQueries[a] -= b;
    a /=2;

    for (; a > 0; a /= 2)
        maximumRangeQueries[a] = max(maximumRangeQueries[2*a], maximumRangeQueries[2*a+1]);

}

int binSearch(int a, int b, int que)
{
    int mid = (a+b)/2;

    if (a == b)
        return a;
    
    if (query(a, mid, 1) >= que)
        return binSearch(a, mid, que);
    return binSearch(mid+1, b, que);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    maximumRangeQueries[LEAVES+n+1] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> maximumRangeQueries[LEAVES + i];
    }
    initiation();

    while (q--)
    {
        int a; cin >> a;

        int res = binSearch(0, n+1, a);

        if (res == n+1)
        {
            cout << 0 << ' ';
            continue;
        }
        cout << res << ' ';
        update(res, a);
    }

}