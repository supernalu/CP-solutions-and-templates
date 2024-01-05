#include <bits/stdc++.h>

using namespace std;

int n;

constexpr long long INF = 1e18;

vector<int> days;

vector<int> cost; 

vector<pair<int,int>> adj[375];

vector<bool> done(375, false);

vector<long long> dist(375, INF);

void dijkstra()
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[days[0]] = 0; 
    pq.push({0, days[0]});

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
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a; 

        cin >> a;

        days.push_back(a);
    }

    for (int i = 0; i < 3; i++)
    {
        int a;

        cin >> a;

        cost.push_back(a);
    }

    for (auto i : days)
    {
        auto it1 = upper_bound(days.begin(), days.end(), i);
        auto it2 = upper_bound(days.begin(), days.end(), i + 6);
        auto it3 = upper_bound(days.begin(), days.end(), i + 29);

        if (it1 == days.end())
        {
            adj[i].push_back({ 366 , cost[0]});
        }
        else
        {
            adj[i].push_back({ days[it1 - days.begin()] , cost[0]});
        }
        if (it2 == days.end())
        {
            adj[i].push_back({ 366 , cost[1]});
        }
        else
        {
            adj[i].push_back({ days[it2 - days.begin()] , cost[1]});
        }
        if (it3 == days.end())
        {
            adj[i].push_back({ 366 , cost[2]});
        }
        else
        {
            adj[i].push_back({ days[it3 - days.begin()] , cost[2]});
        }
    }
    /*
    for (int i = 1; i <= 20; i++)
    {
        cout << i << ": ";

        for (pair<int,int> u : adj[i])
        {
            cout << u.first << ' ' << u.second << ", ";
        }

        cout << endl;
    }
    */

    dijkstra();

    cout << dist[366];




}