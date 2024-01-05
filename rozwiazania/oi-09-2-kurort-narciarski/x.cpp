#include <bits/stdc++.h>

using namespace std;

int n, prim;

int k;

int b, s;

int m;

vector<pair<int,int>>adj[1010];
bool vis[1010][2010];


void bfs(int w)
{
    queue<pair<int, int>> q;   
    
    vis[w][0] = 1;
 
    q.push({w, 0});
    while(q.size() != 0)
    {

        int a = q.front().first;
        int c = q.front().second;

        //cout << a << ' ' << c << endl; 
 
        for (int i = 0; i < adj[a].size(); i++)
        {
            if (c + adj[a][i].second > s) continue;

            if (vis[adj[a][i].first][c + adj[a][i].second]) continue;
 
            q.push({adj[a][i].first, c + adj[a][i].second});            
            vis[adj[a][i].first][c + adj[a][i].second] = 1;
        }
        
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> prim;

    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        int a, b;

        cin >> a >> b;

        adj[a].push_back({b, 0});
    }

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    cin >> b >> s;

    bfs(b);

    int res = 0;

    for (int i = 1; i <= prim; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            //cout << vis[i][j] << ' ';

            if (vis[i][j])
                res = max(res, j);
        }
        //cout << endl;
    }

    cout << s - res;
}