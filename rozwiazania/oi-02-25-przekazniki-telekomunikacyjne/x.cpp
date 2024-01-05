#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1<<20;

struct tree_node
{
    long long a;

    long long sum;

    long long b;

    tree_node()
    {
        a = 0;
        b = 0;
        sum = 0;
    }
};

tree_node x[MAXN];

struct node 
{
    int L;
    int R;

    int ID;

    node(int a, int b, int c)
    {
        L = a; 
        R = b;
        ID = c;
    }

    node go_left()
    {
        return node(L, (L+R)/2, 2*ID);
    }
    node go_right()
    {
        return node((L+R)/2 + 1, R, 2*ID + 1);
    }

    void lazy()
    {
        x[ID].sum += (R-L+1)*x[ID].b + (x[ID].a + x[ID].a*(R-L+1))/2*(R-L+1);

        if (ID < MAXN/2)
        {
            x[ID*2].a += x[ID].a;

            x[ID*2].b += x[ID].b;

            x[2*ID + 1].a += x[ID].a;

            x[2*ID + 1].b += x[ID].b + (x[ID].a + x[ID].a*(R-L+1))/2;         
        }

        x[ID].a = 0;

        x[ID].b = 0;
    }

    
};

int n;



int main()
{
    cin >> n;

    node root(1, MAXN/2, 1);




}