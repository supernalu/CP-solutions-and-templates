#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 50;

constexpr int INF = 1e9;

int n, m, j;

vector<vector<int>> dist(MAXN, vector<int>(MAXN, 0));
vector<vector<int>> spk(MAXN, vector<int>(MAXN, 0));

vector<pair<int, int>> adj = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};

void bfs(vector<pair <int, int>> sup)
{
    deque<pair<int, int>> dq;

    for (auto s : sup)
    {
        dist[s.first][s.second] = 0;
        dq.push_front(s);
    }
    
    while(!dq.empty())
    {
        int v1 = dq.front().first, v2 = dq.front().second;
        dq.pop_front();

        for (auto u: adj)
        {
            if (dist[v1 + u.first][v2 + u.second] > dist[v1][v2] + spk[v1 + u.first][v2 + u.second] )
            {
                dist[v1 + u.first][v2 + u.second] = dist[v1][v2] + spk[v1 + u.first][v2 + u.second];

                if (spk[v1 + u.first][v2 + u.second] == 0) 
                    dq.push_front({v1 + u.first, v2 + u.second});
                else 
                    dq.push_back({v1 + u.first, v2 + u.second}); 
                
            }
        }


    }
}

int main()
{
    cin >> n >> m >> j;
    pair<int,int> tre;
    vector<pair<int,int>> start;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            if (x == '.')            
                dist[i][j] = INF;
            else if (x == 's')
            {
                dist[i][j] = INF;
                spk[i][j] = 1;
            }
            else if (x == '@')
            {
                dist[i][j] = INF;
                start.push_back({i, j});
            }
            else if (x == 'x')
            {
                dist[i][j] = INF;
                tre = {i, j};
            }
            
        }
    }
    /*
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= m+1; j++)
        {
            if (dist[i][j] == INF)
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }
    
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= m+1; j++)
        {
            cout << spk[i][j];
        }
        cout << endl;
    }
    */


    bfs(start);

    /*
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= m+1; j++)
        {
            if (dist[i][j] == INF)
                cout << 1 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    */

    if (j/2 >= dist[tre.first][tre.second])
        cout << "SUCCESS";
    else
        cout << "IMPOSSIBLE";


    
}