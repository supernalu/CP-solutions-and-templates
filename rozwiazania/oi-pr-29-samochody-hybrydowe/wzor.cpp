#include <bits/stdc++.h>

using namespace std;

constexpr int LEAVES = 1 << 20;

constexpr int INI = 0;

constexpr int INF = 1e9;

int n, q, A, B;

vector<int> treeMax(2*LEAVES, INI);

vector<int> lazyAdd(2*LEAVES, INI);

struct node {

    int L;
    int R;

    int id;


    node(int a, int b, int c)
    {
        a = L;
        b = R;
        c = id;

        lazyupdate();
    }

    node left()
    {
        return node(L, (L+R)/2, 2*id);
    }
    node right()
    {
        return node((L+R)/2+1, R, 2*id+1);
    }

    void lazyupdate()
    {
        if (lazyAdd[id] != INI)
        {
            if (id < LEAVES)
            {
                lazyAdd[2*id+1] += lazyAdd[id];

                lazyAdd[2*id] += lazyAdd[id];
            }

            treeMax[id] += lazyAdd[id];

            lazyAdd[id] = INI;
        }
    }

    void rangeAdd(int l, int r, int s)
    {
        if (l > R || r < L)
        {
            return;
        }
        else if (L >= l && R <= r)
        {
            lazyAdd[id] += s;

            lazyupdate();

            return;
        }
        else
        {
            left().rangeAdd(l, r, s);
            right().rangeAdd(l, r, s);
            treeMax[id] = max(treeMax[id * 2], treeMax[id * 2 + 1]);
        }
    }
   
    //* tab[] to tablica sum różnić prefiksowych

    //* ostatni indeks w tab[] ktory jest <= s

    int lastSmallerOrEq(int s)
    {
        if (treeMax[id] <= s)
        {
            return R;
        }
        else if (L == R)
        {
           return -INF; 
        }
        else if (treeMax[left().id] <= s)
        {
            return max(left().lastSmallerOrEq(s), right().lastSmallerOrEq(s)); 
        }
        else
        {
            return left().lastSmallerOrEq(s);
        }
    }

};

struct query
{

    char type;

    int a; 

    int b;

    query(char t, int c, int d = -1)
    {
        type = t;

        a = c;

        b = d;
    }

};


set<int> stacje;

map<int, int> important;

vector<query> v;

int main()
{
    cin >> n >> q >> A >> B;

    while (n--)
    {
        int a;

        cin >> a;

        stacje.insert(a);
    }

    while (q--)
    {
        char a; 

        int b, c;

        cin >> a >> b;

        if (a == 'Z')
        {
            cin >> c;
        }
    }

    for (auto i : stacje)
    {
        important[i] = 0;
    }

    for (auto i : v)
    {
        if (i.type != 'Z')
        {
            important[i.a] = 0;
        }
    }

    int j = 1;

    for (auto& [key, value]: important) {
        value = j++;
    } 

    


}