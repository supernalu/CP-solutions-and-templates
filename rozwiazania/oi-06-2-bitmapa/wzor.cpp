#include <iostream>
#include <queue>

using namespace std;

constexpr int MAXN = 190;

int n, m;

bool adj[MAXN][MAXN];

int odl[MAXN][MAXN];

void bfs(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        pair<int, int> a = { q.front().first, q.front().second };
        q.pop();

        if (odl[a.first + 1][a.second] == -1)
        {
            odl[a.first + 1][a.second] = odl[a.first][a.second] + 1;

            q.push({ a.first + 1, a.second });
        }
        if (odl[a.first - 1][a.second] == -1)
        {
            odl[a.first - 1][a.second] = odl[a.first][a.second] + 1;

            q.push({ a.first - 1, a.second });
        }
        if (odl[a.first ][a.second + 1] == -1)
        {
            odl[a.first ][a.second + 1] = odl[a.first][a.second] + 1;

            q.push({ a.first , a.second + 1});
        }
        if (odl[a.first][a.second - 1] == -1)
        {
            odl[a.first][a.second - 1] = odl[a.first][a.second] + 1;

            q.push({ a.first , a.second - 1 });
        }
    }
}

int main()
{
    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            odl[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        string pom;
        cin >> pom;
        for (int j = 1; j <= m; j++)
        {            
            if (pom[j - 1] == '1')
            {
                adj[i][j] = 1;
            }
            else
            {
                adj[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {               
        for (int j = 1; j <= m; j++)
        {
            //cin >> adj[i][j];
            if (adj[i][j])
            {
                odl[i][j] = 0;
                q.push({ i, j });
            }
            else
            {
                odl[i][j] = -1;
            }
        }
    }
    /*
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
            cout << odl[i][j] << ' ';
        cout << endl;
    }
    */

    bfs(q);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << odl[i][j] << ' ';
        cout << endl;
    }





}