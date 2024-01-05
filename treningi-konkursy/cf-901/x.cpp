#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k;
long long a[5010];
long long il[5010];
long long dp[5010];

/*
int dist[5010][5010];
void dijkstra(int mex)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
 
    dist[0][mex] = 0; 
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
*/
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = 1e9+10;
        }
        for (int i = 0; i <= n; i++)
            il[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            il[min(a[i], n)]++;
        }
        int mex;
        for (int i = 0; i <= n; i++)
            if (il[i] == 0)
            {
                mex = i;
                break;
            } 
        dp[mex] = 0;
        for (int i = 0; i <= 500; i++)
        {
            for (int j = n; j >= 0; j++)
            {
                if (dp[j] == 1e9+10)
                    continue;
                dp[0] = min(dp[j]+(il[0]-1)*j, dp[0]);
                for (int k = 1; il[k] < il[k-1] && k < j; k++)
                {
                    dp[k] = min(dp[j]+(il[k]-1)*j+k, dp[k]);
                }
            }
        }
        cout << dp[0] << '\n';
    }
}