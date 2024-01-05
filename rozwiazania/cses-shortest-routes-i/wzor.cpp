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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    dijkstra();

    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    

    
}