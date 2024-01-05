#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 5e5 + 10;
constexpr int LEAVES = 1<<19;

int n;
int res = 1;
vector<int> adj[MAXN];
vector<int> parent(MAXN, 1e9);
vector<int> neighbours;
pair<int, int> range[MAXN];
int id[MAXN];
int l[2*LEAVES], r[2*LEAVES];
int rangeQuerry[2*LEAVES];
int lazy[2*LEAVES];

void bfs()
{
    queue<int> q;
    q.push(1); neighbours.push_back(0); neighbours.push_back(1);
    int iterator = 2;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        //cout << v << ' ';

        for (auto u : adj[v])
        {
            if (u == parent[v])
                continue;
            
            parent[u] = v;
            q.push(u);
            neighbours.push_back(u);
        }
      
        range[v] = {iterator, iterator + adj[v].size()-2};
        //cout << iterator << ' ' << iterator + adj[v].size()-2 << '\n';
        iterator += adj[v].size()-1;
        
    }
}

//*kod drzewa przedziałowego

void initiation()
{
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        l[i] = i - LEAVES;
        r[i] = i - LEAVES;
        if (i-LEAVES <= n)
            rangeQuerry[i] = adj[neighbours[i-LEAVES]].size();
    }
    for (int i = LEAVES-1; i > 0; i--)
    {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
    }
}

void lazypropagation(int v)
{
    if (lazy[v] == 0)
        return;

    if (v < LEAVES)
    {
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
    }
    rangeQuerry[v] += lazy[v];
    lazy[v] = 0;
}

void update(int left, int right, int v, int change)
{
    lazypropagation(v);
    if (right < l[v] || r[v] < left)
        return;
    if (left <= l[v] && r[v] <= right)
    {
        lazy[v] += change;
        lazypropagation(v);
        return;
    }
    update(left, right, 2*v, change); update(left, right, 2*v+1, change);
}

int querry(int position, int v)
{
    lazypropagation(v);
    if (r[v] < position || position < l[v])
        return 0;
    if (l[v] == position && position == r[v])
    {
        return rangeQuerry[v];
    }
    return (querry(position, 2*v) + querry(position, 2*v+1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[1].push_back(0);
    parent[1] = 0;
    bfs();

    adj[1].pop_back();
    
    for (int i = 0; i <= n; i++)
    {
        id[neighbours[i]] = i;
    }


    initiation();

    int q; cin >> q;

    while (q--)
    {
        int a; cin >> a; 

        if (a > 0)
        {
            int tmp = querry(id[a], 1);
            if (range[a].first <= range[a].second)
                update(range[a].first, range[a].second, 1, -1);
            update(id[parent[a]], id[parent[a]], 1, -1);

            //cout << tmp << '\n';
            res += (tmp-1);
        }
        else
        {
            a = abs(a);
            int tmp = querry(id[a], 1);
            if (range[a].first <= range[a].second)
                update(range[a].first, range[a].second, 1, 1);
            update(id[parent[a]], id[parent[a]], 1, 1);

            
            //cout << tmp << '\n';
            res -= (tmp-1);
        }
        /*
        for (int i = 1; i <= n; i++)
            cout << querry(i, 1) << ' ';
        cout << '\n';
        */
        

        cout << res << '\n';
    }

    
    


}