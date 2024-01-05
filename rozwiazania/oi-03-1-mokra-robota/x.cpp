#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 50;
constexpr int INF = 1e9 + 10;

int n;
int dist[MAXN][MAXN][MAXN][MAXN];

vector<int> a(4, 0);
vector<int> b(4, 0);

void bfs()
{
    queue<vector<int>>q;

    q.push(a);

    dist[a[0]][a[1]][a[2]][a[3]] = 0;

    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();

        //cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << '\n';

        for (int i = 0; i < n; i++)
        {
            vector<int> u = v;

            u[i] = 0;

            if (dist[u[0]][u[1]][u[2]][u[3]] != INF)
                continue;

            q.push(u);
            dist[u[0]][u[1]][u[2]][u[3]] = dist[v[0]][v[1]][v[2]][v[3]]+1;
        }
        
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == j)
                    continue;

                vector<int> u = v;

                int k = min(v[j], a[i]-v[i]);
   
                u[i] = v[i] + k;
                u[j] = v[j] - k;


                if (dist[u[0]][u[1]][u[2]][u[3]] != INF)
                    continue;

                q.push(u);
                dist[u[0]][u[1]][u[2]][u[3]] = dist[v[0]][v[1]][v[2]][v[3]]+1;
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            for (int k = 0; k < 50; k++)
            {
                for (int l = 0; l < 50; l++)
                    dist[i][j][k][l] = INF;
            }
        }
    }

    bfs();

    if (dist[b[0]][b[1]][b[2]][b[3]] == INF)
    {
        cout << "NIE";
        return 0;
    }

    cout << dist[b[0]][b[1]][b[2]][b[3]];


    




}