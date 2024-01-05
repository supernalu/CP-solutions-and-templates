#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 510;

int n, m, k;

char a[MAXN][MAXN];

bool vis[MAXN][MAXN];

int il = 0;

void bfs(int c, int b)
{
    queue<pair<int, int>> q;

    q.push({c, b});

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second; 

        il++;

        if (il > k)
            a[x][y] = 'X';
            
        

        q.pop();

        vis[x][y] = true;

        if (a[x+1][y] == '.' && !vis[x+1][y])
        {
            q.push({x+1, y});
            vis[x+1][y] = true;
        }
        if (a[x-1][y] == '.' && !vis[x-1][y])
        {
            q.push({x-1, y});
            vis[x-1][y] = true;
        }
        if (a[x][y+1] == '.' && !vis[x][y+1])
        {
            q.push({x, y+1});
            vis[x][y+1] = true;
        }
        if (a[x][y-1] == '.' && !vis[x][y-1])
        {
            q.push({x, y-1});
            vis[x][y-1] = true;
        }        
    }
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            a[i][j] = '#';   

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] + 1;

        a[i][m+1] = '#';
    }

    int ile = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '.')
                ile++;
    }

    //cout << ile << endl;

    k = ile - k;

    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (a[i][j] == '.')
            {
                bfs(i, j);

                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                        cout << a[i][j];
                    cout << '\n';
                }

                return 0;
            }
        }
    }


    
}