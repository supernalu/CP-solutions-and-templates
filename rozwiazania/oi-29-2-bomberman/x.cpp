#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

constexpr int INF = 1e9 + 10;

int n;

char ma[MAXN][MAXN];

int dist[MAXN][MAXN];

pair<int, int> parent[MAXN][MAXN];

pair<int, int> mov[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char m[4] = {'D', 'G', 'L', 'P'};

pair<int, int> st;

pair<int, int> ko;

void bfs(pair<int, int> s)
{
    queue<pair<int, int>> q;

    dist[s.first][s.second] = 0;

    parent[s.first][s.second] = s;

    q.push(s);

    while (!q.empty())
    {
        pair<int, int> v = q.front();

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = v.first + mov[i].first, y = v.second + mov[i].second;

            if (dist[x][y] != INF)
                continue;

            
            dist[x][y] = dist[v.first][v.second]+1;
            q.push({x, y});

            parent[x][y] = {v.first, v.second};
        }     
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= n+1; j++)
        {
            dist[i][j] = -1;
        }
    }

    int il = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ma[i][j];

            if (ma[i][j] == '.')
                dist[i][j] = INF;

            else if (ma[i][j] == '#')
                il++;
            else if (ma[i][j] == 'P')
            {
                st = {i, j};

                dist[i][j] = INF;
            }
            else if (ma[i][j] == 'K')
            {
                ko = {i, j};

                dist[i][j] = INF;
            }
        }
    }

    if (il == 0)
    {
        bfs(st);

        if (dist[ko.first][ko.second] != INF)
        {
            cout << dist[ko.first][ko.second] << '\n';

            cout << "1 1 \n";

            vector<char> road;

            pair<int, int> x;

            x.first = ko.first; x.second = ko.second;

            while (parent[x.first][x.second] != x)
            {
                for (int i = 0; i <= 3; i++)
                {
                    if (parent[x.first][x.second].first + mov[i].first == x.first && parent[x.first][x.second].second + mov[i].second == x.second)
                        road.push_back(m[i]);
                }
                

                x.first = parent[x.first][x.second].first; x.second = parent[x.first][x.second].second;
            }
            reverse(road.begin(), road.end());

            for (auto i : road)
                cout << i;
        }
        else
        {
            cout << "NIE";
        }

    }
    else //if (n <= 50)
    {
        int res = INF;

        pair<int, int>bomb;

        vector<char> road;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ma[i][j] != 'X')
                {
                    for (int i = 1; i <= n; i++)
                    {
                        for (int j = 1; j <= n; j++)
                        {


                            if (ma[i][j] == '.')
                                dist[i][j] = INF;

                            else if (ma[i][j] == 'P')
                            {
                                

                                dist[i][j] = INF;
                            }
                            else if (ma[i][j] == 'K')
                            {
                                

                                dist[i][j] = INF;
                            }
                        }
                    }

                    for (int k = i; k <= n; k++)
                    {
                        if (ma[k][j] == 'X')
                            break;

                        dist[k][j] = INF;
                    }
                    for (int k = j; k <= n; k++)
                    {
                        if (ma[i][k] == 'X')
                            break;

                        dist[i][k] = INF;
                    }
                    for (int k = i; k > 0; k--)
                    {
                        if (ma[k][j] == 'X')
                            break;

                        dist[k][j] = INF;
                    }
                    for (int k = j; k > 0; k--)
                    {
                        if (ma[i][k] == 'X')
                            break;

                        dist[i][k] = INF;
                    }

                    bfs(st);

                    /*
                    if (i == 2 && j == 3)
                    {
                        for (int i = 1; i <= n; i++)
                        {
                            for (int j = 1; j <= n; j++)
                                cout << dist[i][j] << ' ';
                            cout << endl;
                        }
                    }
                    */

                    //cout << dist[ko.first][ko.second] << endl;

                    if (res > dist[ko.first][ko.second])
                    {
                        res = dist[ko.first][ko.second];

                        bomb = {i, j};
                    }

                    for (int k = i; k <= n; k++)
                    {
                        if (ma[k][j] == 'X')
                            break;

                        
                        if (ma[k][j] == '#')
                            dist[k][j] = -1;
                    }
                    for (int k = i; k <= n; k++)
                    {
                        if (ma[i][k] == 'X')
                            break;

                        if (ma[i][k] == '#')
                            dist[i][k] = -1;
                    }
                    for (int k = i; k > 0; k--)
                    {
                        if (ma[k][j] == 'X')
                            break;

                        if (ma[k][j] == '#')
                            dist[k][j] = -1;
                    }
                    for (int k = i; k > 0; k--)
                    {
                        if (ma[i][k] == 'X')
                            break;

                        if (ma[i][k] == '#')
                            dist[i][k] = -1;
                    }
                }
            }
        }

        cout << res << '\n' << bomb.first << ' ' << bomb.second << '\n';

        /*
        pair<int, int> x;

        x.first = ko.first; x.second = ko.second;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                parent[i][j] = {0, 0};

                if (ma[i][j] == '.')
                        dist[i][j] = INF;

                else if (ma[i][j] == 'P')
                {
                                

                    dist[i][j] = INF;
                }
                else if (ma[i][j] == 'K')
                {
                                

                    dist[i][j] = INF;
                }
            }
        }

        for (int k = bomb.first; k <= n; k++)
        {
            if (ma[k][bomb.second] == 'X')
                break;

            dist[k][bomb.second] = INF;
        }
        for (int k = bomb.second; k <= n; k++)
        {
            if (ma[bomb.first][k] == 'X')
                break;

            dist[bomb.first][k] = INF;
        }
        for (int k = bomb.first; k > 0; k--)
        {
            if (ma[k][bomb.second] == 'X')
                break;

            dist[k][bomb.second] = INF;
        }
        for (int k = bomb.second; k > 0; k--)
        {
            if (ma[bomb.first][k] == 'X')
                break;

            dist[bomb.first][k] = INF;
        }

        bfs(st);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << parent[i][j].first << ' ' << parent[i][j].second << "  " ;
            }
            cout << endl;
        }

        while (parent[x.first][x.second] != x)
        {
            for (int i = 0; i <= 3; i++)
            {
                if (parent[x.first][x.second].first + mov[i].first == x.first && parent[x.first][x.second].second + mov[i].second == x.second)
                    road.push_back(m[i]);
            }
            

            x.first = parent[x.first][x.second].first; x.second = parent[x.first][x.second].second;
        }
        reverse(road.begin(), road.end());

        for (auto i : road)
            cout << i;

        */
    }


}