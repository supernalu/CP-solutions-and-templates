#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 505;
constexpr long long INF = 1e18;
 
int n, m, q;
 
 
 
vector<vector<long long>> dist(MAXN, vector<long long> (MAXN, 0));
 
void floyd_warshall()
{
    for (int i = 1; i <= n; i++)
        dist[i][i] = INF;
        
    for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
 
    for (int i = 1; i <= n; i++)
    {
        cin >> m;

        for (int j = 0; j < m; j++)
        {
            int a = i, b; long long c;
            cin >> b >> c;
    
            dist[a][b] = max(dist[a][b], c);
        }
    }
 
    floyd_warshall();

    cin >> q;
 
    for (int i = 1; i <= q; i++)
    {
        int d, e;
 
        cin >> d >> e;
    
        cout << dist[d][e] << '\n';
    }
 
}