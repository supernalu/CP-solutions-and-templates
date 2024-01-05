#include<bits/stdc++.h>

using namespace std;
constexpr int LEAVES = 1 << 19;

vector<int> sumRangeQuery(2*LEAVES, 0);
vector<int> l(2*LEAVES);
vector<int> r(2*LEAVES);
vector<int> lazy(2*LEAVES, 0);

void prepare()
{
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        l[i] = i-LEAVES;
        r[i] = i-LEAVES;
    } 
    for (int i = LEAVES-1; i > 0; i++)
    {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
    }
}

void lazypropagation(int v)
{
    if (lazy[v] == 0)
        return;
    sumRangeQuery[v] += lazy[v]*(r[v]-l[v]+1);
    if (v < LEAVES)
    {
        lazy[2*v] = lazy[v];
        lazy[2*v+1] = lazy[v];
    }
    lazy[v] = 0;
}

int query(int a, int b, int v)
{
    if (l[v] > b || r[v] < a)
        return 0;
    lazypropagation(v);
    if (l[v] <= a && r[v] >= b)
        return sumRangeQuery[v];
    return query(a, b, 2*v) + query(a,b, 2*v+1);
}

void update(int a, int b, int v, int val)
{
    if (l[v] > b || r[v] < a)
        return;
    lazypropagation(v);
    if (l[v] <= a && r[v] >= b)
    {
        lazy[v] = val;
        lazypropagation(v);
        return;
    }
    update(a, b, 2*v, val);
    update(a, b, 2*v+1, val);
    sumRangeQuery[v] = sumRangeQuery[2*v] + sumRangeQuery[2*v+1];
}

int main()
{

}