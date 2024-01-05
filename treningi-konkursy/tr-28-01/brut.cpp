#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e6 + 10;

int n, k;
vector<int> adj[MAXN];
bool vis[MAXN];
int odl[MAXN];
int parent[MAXN];
queue<int>s;
vector<int>res;

void debug()
{
    cout << "debug";
}

void initationOdl()
{
    for (int i = 1; i <= n; i++)
    {
        odl[i] = 1e9;
        parent[i] = 0;
    }
}

void bfs()
{
    while (!s.empty())
    {
        int v = s.front();
        s.pop();
        //cout << v;

        for (auto u: adj[v])
        {
            if (odl[u] != 1e9 || vis[u])
                continue;
            
            odl[u] = odl[v]+1;
            parent[u] = v;
            s.push(u);
        }
    }
}

void findDiam()
{
    //cout << "l";
    
    s.push(1);
    odl[1] = 0;
    bfs();

    int maxi = 1;
    for (int i = 1; i <= n; i++)
    {
        if (odl[maxi] <= odl[i])
            maxi = i;
    }
    res.push_back(maxi);
    
    initationOdl();

    s.push(maxi);
    odl[maxi] = 0;
    bfs();
    
    int maxi2 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (odl[maxi2] <= odl[i])
            maxi2 = i;
    }
    res.push_back(maxi2); 
    
    while (maxi2 != maxi)
    {
        vis[maxi2] = 1;
        maxi2 = parent[maxi2];
        //cout << maxi2 << endl;
       
    }

    vis[maxi] = 1;  
    
    
    
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        
        int a, b; cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    findDiam();
    
    /*
    for (int i = 1; i <= n; i++)
    {
        cout << vis[i] << ' ';
    }
    */
    
    
    k-=2; 
    int maxi;
    while (k >= 0)
    {
        initationOdl();
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                s.push(i);
                odl[i] = 0;
            }
        }
        bfs();

        int il = 0; maxi = 0;

        for (int i = 1; i <= n; i++)
        {
            if (odl[i] == maxi)
                il++;
            if (odl[i] > maxi)
            {
                il = 1;
                maxi = odl[i];
            }
        }
        if (il > k)
        {
            break;
        }
        k -= il;
        for (int i = 1; i <= n; i++)
        {
            if (odl[i] != maxi)
                continue;
            
            res.push_back(i);
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                j = parent[k];
            }
        }
    }
    cout << maxi << ' ' << res.size() << '\n';
    for (auto i : res)
        cout << i << ' ';


}