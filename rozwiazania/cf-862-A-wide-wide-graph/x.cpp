#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
long long k, c;
vector<int> adj[MAXN];
long long odl[MAXN][3];
int maxi[MAXN];
void bfs(int st, int it)
{
    odl[st][it] = 0;
    queue<int>q;
    q.push(st);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto u : adj[v])
        {
            if (odl[u][it] != -1)
                continue;
            odl[u][it] = odl[v][it]+1;
            q.push(u);
        }
    }
}
int findMaxi(int it)
{
    int id = 1;
    for (int i = 1; i <= n; i++)
    {
        if (odl[i][it] > odl[id][it])
            id = i;
    }
    return id;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        odl[i][0] = -1; odl[i][1] = -1; odl[i][2] = -1;
        maxi[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1, 0);
    bfs(findMaxi(0), 1);
    bfs(findMaxi(1), 2);
    int res = 0;
    for (int i = 1; i <= n; i++)
        maxi[max(odl[i][1], odl[i][2])+1]++;

    for (int i = 1; i <= n; i++)
    {
        res += maxi[i];
        cout << min(res+1, n) << ' ';
    }  
        
    
}