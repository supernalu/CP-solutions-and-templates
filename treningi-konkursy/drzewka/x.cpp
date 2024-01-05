#include <bits/stdc++.h>

using namespace std;
constexpr int LEAVES = 1 << 19;

vector<int>minimumRangeQuery(2*LEAVES, 1e9);
vector<int>l(2*LEAVES);
vector<int>r(2*LEAVES);
vector<int>lazy(2*LEAVES, 1e9);
int n, q;

void prepare() {
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        l[i] = i-LEAVES;
        r[i] = i-LEAVES;
    }
    for (int i = LEAVES-1; i > 0; i--)
    {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
        minimumRangeQuery[i] = min(minimumRangeQuery[2*i], minimumRangeQuery[2*i+1]);
    }
}

void lazyPropagation(int a)
{
    if (lazy[a] == 1e9)
        return;   
    
    minimumRangeQuery[a] = lazy[a];
    if (a < LEAVES)
    {
        lazy[2*a] = lazy[a];
        lazy[2*a+1] = lazy[a];
    }
    lazy[a] = 1e9;
}

int query(int a, int b, int v)
{
    if (r[v] < a || l[v] > b)
        return 1e9;
    lazyPropagation(v);
    if (l[v] >= a && r[v] <= b)
        return minimumRangeQuery[v];
    return min(query(a, b, 2*v), query(a, b, 2*v+1));
}

void update(int a, int b, int v, int val)
{
    if (r[v] < a || l[v] > b)
        return;
    lazyPropagation(v);
    if (l[v] >= a && r[v] <= b) {
        lazy[v] = val;
        lazyPropagation(v);
        return;
    }
    update(a, b, 2*v, val);
    update(a, b, 2*v+1, val);
    minimumRangeQuery[v] = min(minimumRangeQuery[2*v], minimumRangeQuery[2*v+1]);
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> minimumRangeQuery[LEAVES + i];
    }
    prepare();

   
    while (q--)
    {
        int type; cin >> type; 

        if (type == 1)
        {
            int a, b; cin >> a >> b;

            cout << query(a, b, 1) << '\n';
        }
        else
        {
            int a, b, c; 
            cin >> a >> b >> c;
            update(a, b, 1, c);
        }
    }
}
