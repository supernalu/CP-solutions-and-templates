#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 5010;
constexpr long long INF = 1e18;
constexpr long long ZN = 2e18;

int n, m;

vector<tuple<int, int, int>>edgel;
vector <long long> dist(MAXN, -INF);
bool vis[10000];
vector<int>adj[10000];

void bellman_ford(int s)
{
    
    dist[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto e: edgel)
        {
            if  (dist[get<0>(e)] == -INF) continue;

            if  (dist[get<1>(e)] < dist[get<0>(e)] + get<2>(e))
            {
                dist[get<1>(e)] = dist[get<0>(e)] + get<2>(e);                
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto e: edgel)
        {
            if  (dist[get<0>(e)] == -INF) continue;

            if  (dist[get<1>(e)] < dist[get<0>(e)] + get<2>(e))
            {
                dist[get<1>(e)] = -ZN;                   
            }
        }
    }



}

void bfs(int s)
{
    queue< int > q;
       
    vis[s] = 1;
    dist[s] = -1;
    q.push(s);
    while(q.size() != 0)
    {
        int a = q.front();
 
        for (int i = 0; i < adj[a].size(); i++)
        {
            if (vis[adj[a][i]]) continue;

            dist[adj[a][i]] = -1;
            q.push(adj[a][i]);                        
            vis[adj[a][i]] = 1;
        }
        
        q.pop();
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgel.push_back({a, b, c});
        adj[a].push_back(b);
    }
    bellman_ford(1);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && dist[i] == -ZN)
            bfs(i);
    }

    cout << dist[n];

}