class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        constexpr long long INF = 1e18;
        
        vector<pair<int,int>> adj[375];

        vector<bool> done(375, false);

        vector<long long> dist(375, INF);
        
        int n = days.size();
        
        for (auto i : days)
    {
        auto it1 = upper_bound(days.begin(), days.end(), i);
        auto it2 = upper_bound(days.begin(), days.end(), i + 6);
        auto it3 = upper_bound(days.begin(), days.end(), i + 29);

        if (it1 == days.end())
        {
            adj[i].push_back({ 366 , costs[0]});
        }
        else
        {
            adj[i].push_back({ days[it1 - days.begin()] , costs[0]});
        }
        if (it2 == days.end())
        {
            adj[i].push_back({ 366 , costs[1]});
        }
        else
        {
            adj[i].push_back({ days[it2 - days.begin()] , costs[1]});
        }
        if (it3 == days.end())
        {
            adj[i].push_back({ 366 , costs[2]});
        }
        else
        {
            adj[i].push_back({ days[it3 - days.begin()] , costs[2]});
        }
    }
        
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
        
      return( dist[366]);  
    }
};