#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;
constexpr long long INF = 1e14+1;

int n, m;

vector<tuple<int, int, int>> adj[MAXN][2];
bool done[MAXN][2];
long long dist[MAXN][2];

void dijkstra()
{
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

    dist[1][0] = 0; 
    pq.push({0, 1, 0});

    while (!pq.empty())
    {
        int v1 = get<1>(pq.top()), v2 = get<2>(pq.top());
        pq.pop();

        if (done[v1][v2]) continue;

        done[v1][v2] = true;
        for (auto u: adj[v1][v2])
        {
            if (dist[get<0>(u)][get<1>(u)] > dist[v1][v2] + get<2>(u))  
            {         
                dist[get<0>(u)][get<1>(u)] = dist[v1][v2] +  get<2>(u);
                pq.push({dist[get<0>(u)][get<1>(u)], get<0>(u), get<1>(u)});
            }

            
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }


    for (int i = 1; i <= m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a][0].push_back({b, 0, c});
        adj[a][1].push_back({b, 1, c});  
        adj[a][0].push_back({b, 1, c/2});  
    }

    dijkstra();

    cout << dist[n][1];
}