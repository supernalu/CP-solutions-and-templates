#include <bits/stdc++.h>

using namespace std;

constexpr int LEAVES = 1 << 19;

vector<int>sumRangeQuery(2*LEAVES, 0);
vector<int> l(2*LEAVES);
vector<int> r(2*LEAVES);

void prepare()
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

int query(int a, int b, int v)
{
    if (l[v] >= a && r[v] <= b)
        return sumRangeQuery[v];  
    if (l[v] > b || r[v] < a)
        return 0;
    return query(a, b, 2*v)+query(a, b, 2*v+1);
}

void update(int a, int b)
{
    a += LEAVES;
    sumRangeQuery[a] += b;
    a /= 2;

    for (; a > 0; a /= 2)
        sumRangeQuery[a] += b;
}

int main()
{
    int n, q;
    cin >> n >> q;
    prepare();

    update(5, 10);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        
        cout << query(a, b, 1) << endl;
    }
}
