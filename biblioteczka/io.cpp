#include <bits/stdc++.h>
using namespace std; 
constexpr int MAXN = 2e5 + 5; 
constexpr long long INF = 1e18;
int n, m;
vector<bool> done(MAXN, false);
vector<pair<int, int>> adj[MAXN];
vector<long long> dist(MAXN, INF);

void dijkstra()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[1] = 0; 
    pq.push({0, 1});
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if (done[v]) continue;
        done[v] = true;
        for (auto u: adj[v])
        {
            if (dist[u.first] > dist[v] + u.second)  
            {         
                dist[u.first] = dist[v] + u.second;
                pq.push({dist[u.first], u.first});
            }
 
            
        }
    }
}

vector<vector<long long>> dist(MAXN, vector<long long> (MAXN, INF));
void floyd_warshall()
{
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
     
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 
}



vector<tuple<int, int, int>> edgel;
vector <long long> dist(MAXN, 0);
vector<int> parent(MAXN, -1);
bool poss;
int w;
vector<int> res;
void bellman_ford()
{  
    for (int i = 1; i < n; i++)
    {
        for (auto e: edgel)
        {           
 
            if  (dist[get<1>(e)] > dist[get<0>(e)] + get<2>(e))
            {
                dist[get<1>(e)] = dist[get<0>(e)] + get<2>(e);
                parent[get<1>(e)] = get<0>(e);
            }
        }
    }
    for (auto e: edgel)
        {           
            if  (dist[get<1>(e)] > dist[get<0>(e)] + get<2>(e))
            {
                poss = 1;
                w = get<1>(e);
                parent[get<1>(e)] = get<0>(e);
            }
        }
}


