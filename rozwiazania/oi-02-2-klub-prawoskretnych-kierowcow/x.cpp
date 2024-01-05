#include <bits/stdc++.h>

constexpr int MAXN = 110;

constexpr int INF = 1e9;

#define left 3
#define right 1
#define down 0
#define up 2

using namespace std;

struct vertex
{
    int x;

    int y;

    int k;
};

int n, m;

pair<int, int> A, B;

vector<vector<bool>> a(MAXN, vector<bool>(MAXN, true));

int dist[4][MAXN][MAXN];

vertex parent[4][MAXN][MAXN];



vector<vertex> getNeighbours(vertex s) {
    if (s.k == down)
    {
        return {{s.x+1, s.y, down}, {s.x, s.y-1, left}};
    }
    else if (s.k == up)
    {
        return {{s.x-1, s.y, up}, {s.x, s.y+1, right}};
    }
    else if (s.k == right)
    {
        return {{s.x+1, s.y, down}, {s.x, s.y+1, right}};
    }
    else 
    {
        return {{s.x-1, s.y, up}, {s.x, s.y-1, left}};
    }

}

void bfs()
{
    for (int i = 0; i < 4; i++)
    {
        dist[i][A.first][A.second] = 0;
        parent[i][A.first][A.second] = {A.first, A.second, i};
    }

    queue<vertex> q;

    for (int i = 0; i < 4; i++)
    {
        q.push({A.first, A.second, i});
    }

    while (!q.empty())
    {
        vertex v = q.front();

        q.pop();

        for (auto u : getNeighbours(v)) {
            //cout << u.x << ' ' << u.y << ' ' << u.k << endl;

            if (a[u.x][u.y] == 0 && dist[u.k][u.x][u.y] == INF)
            {
                q.push(u);

                parent[u.k][u.x][u.y] = v;

                dist[u.k][u.x][u.y] = dist[v.k][v.x][v.y]+1;
            }
        }

        
    }
}

int main()
{

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < MAXN; ++j)
            for (int k = 0; k < MAXN; ++k)
                dist[i][j][k] = INF;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string s;

        cin >> s;

        for (int j = 0; j < m; j++)
        {
            if (s[j] == '0')
                a[i][j+1] = 0;
            else
                a[i][j+1] = 1;
        }
    }

    cin >> A.first >> A.second >> B.first >> B.second;

    bfs();

    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (min({dist[0][i][j], dist[1][i][j], dist[2][i][j], dist[3][i][j]}) == INF)
            {
                cout <<"s ";
                continue;
            }
            cout << min({dist[0][i][j], dist[1][i][j], dist[2][i][j], dist[3][i][j]}) << ' ';
        }
        cout << '\n';
    }
    */

    if (min({dist[0][B.first][B.second], dist[1][B.first][B.second], dist[2][B.first][B.second], dist[3][B.first][B.second]}) == INF)
    {
        cout << "NIE\n";
        return 0;
    }

    //cout << min({dist[0][B.first][B.second], dist[1][B.first][B.second], dist[2][B.first][B.second], dist[3][B.first][B.second]})+1;

    int mini = INF + 10, miniID;

    for (int i = 0; i < 4; i++)
    {
        if (dist[i][B.first][B.second] < mini)
        {
            mini = dist[i][B.first][B.second];
            miniID = i;
        }
    }

    cout << mini+1 << '\n';

    vector<pair<int, int>>res;
    int a = B.first, b = B.second, c = miniID;
    vertex d;
    d.x = a; d.y = b; d.k = c;

    //cout << (parent[c][a][b].x != d.x) << ' ' << (parent[c][a][b].y != d.y) << ' ' << (parent[c][a][b].k != d.k) << ' ';

    while (parent[c][a][b].x != d.x || parent[c][a][b].y != d.y )
    {
        res.push_back({d.x, d.y});
        d.x = parent[c][a][b].x;
        d.y = parent[c][a][b].y;
        d.k = parent[c][a][b].k;

        int e = a, f = b, g = c;

        a = parent[g][e][f].x;
        b = parent[g][e][f].y;
        c = parent[g][e][f].k;
    }

    res.push_back({A.first, A.second});
    reverse(res.begin(), res.end());

    for (auto i : res)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}