#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

int w1, w2;

int px, py, kx, ky;

int n;

int vis[MAXN][MAXN];

pair<int, int> ods[MAXN*MAXN];

pair<int, int> change[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs()
{
    if (vis[px][py] == 2)
    {
        vis[kx][ky] = 2;
    }

    vis[px][py] = 1;

    queue<pair<int, int>> q;

    q.push({px, py});

    while (!q.empty())
    {


        int a = q.front().first, b = q.front().second;
        //cout << a << ' ' << b << endl;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (vis[a + change[i].first][b + change[i].second] == 0)
            {
                vis[a + change[i].first][b + change[i].second] = 1;
                q.push({a + change[i].first, b + change[i].second});
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> w1 >> w2;

    cin >> px >> py >> kx >> ky;

    cin >> n;

    py = w2 - py + 1;
    ky = w2 - ky + 1;

    for (int i = 1; i <= n; i++)
    {
        int pom1, pom2;

        cin >> pom1 >> pom2;

        ods[i] = {pom1, w2 - pom2 + 1};
    }

    for (int i = 0; i <= w1; i++)
    {
        vis[i][0] = 1;
        vis[i][w2+1] = 1;
    }
    for (int i = 0; i <= w2; i++)
    {
        vis[0][i] = 1;
        vis[w1 + 1][i] = 1;
    }



    for (int i = 0; i <= max(w1, w2); i++)
    {

        for (int k = 1; k <= n; k++)
        {
            for (int j = max(0, ods[k].first - i); j <= min(w1, ods[k].first + i); j++)
                for ( int l = max(0, ods[k].second - i); l <= min(w2, ods[k].second + i); l++)
                    vis[j][l] = 2;
        }

        

        bfs();

       
        /*
        for (int k = 1; k <= w1; k++)
        {
            for (int j = 1; j <= w2; j++)
                cout << vis[k][j] << ' ';

            cout << endl;
        }

        cout << endl;
        */
        
        

        if (vis[kx][ky] == 0 or vis[kx][ky] == 2)
        {
            cout << i*i;
            return 0;
        }

        for (int k = 1; k <= w1; k++)
            for (int j = 1; j <= w2; j++)
                vis[k][j] = 0;
    }
}