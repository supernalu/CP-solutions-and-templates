#include <bits/stdc++.h>

constexpr int MAXN = 5e5 + 10;
constexpr int LEAVES = 1<<19;
//constexpr int LEAVES = 16;

using namespace std;

int n;
vector<int> adj[MAXN];
pair<int, int> a[MAXN];
int dist[MAXN];
vector<int> x(2*LEAVES);

void lazy(int i)
{
    if (i <= LEAVES)
    {
        x[2*i] += x[i];
 
        x[2*i+1] += x[i];
 
        x[i] = 0;
    }
}

int read(int r)
{
    r += LEAVES;    

    int res = 0;
 
    for (; r >= 1; r /= 2)
    {
        //cout << r << ' ' << x[r] << '\n';
        res += x[r];
    }
            
    return res;
}

void update(int c, int d, int e)
{
    c += LEAVES;
    d += LEAVES;
 
    while (c <= d)
    {
        if (d == c)
        {
            x[d] += e;
            lazy(d);
 
            break;
        }
        if (c%2 == 1)
        {
            x[c] += e;
            lazy(c);
 
            c++;
        }
        if (d%2 == 0)
        {
            x[d] += e;
            lazy(d);
 
            d--;
        }
 
        c /= 2;
        d /= 2;
    }
}
int k = 1;

void dfs(int v)
{
    a[v].first = k; 
    k++;
    for (auto u : adj[v]){
        dist[u] = dist[v]+1;
        dfs(u);
    }
    a[v].second = k;
    k++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
    }
    dist[1] = 0;
    dfs(1);

    /*
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].first << ' ' << a[i].second << '\n';
    }*/

    int q; cin >> q;

    q = q + n - 1;

    while(q--)
    {
        char w; cin >> w;

        if (w == 'W')
        {
            int b; cin >> b;
            cout <<  dist[b] - read(a[b].first) << '\n';
        }
        else 
        {
            int b, c; cin >> b >> c;

            update(a[c].first, a[c].second, 1);
        }
        
        
    }
}