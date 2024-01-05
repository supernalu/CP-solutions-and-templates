#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1010;

int n, m;

vector <vector<int>> adj(MAXN, vector<int>(MAXN, 2));

//vector <vector<pair<int,int>>> parent(MAXN, vector<pair<int, int>>(MAXN, {0, 0}));

vector<pair<int, int>> lol = {{0, 1}, {0,-1}, {1, 0}, {-1, 0}};
vector<char> lmao = {'R', 'L', 'D', 'U'};

vector <vector<char>> parent2(MAXN, vector<char>(MAXN, '0'));

void bfs(vector<pair <int, int>> sup)
{
    deque<pair<int,int>> q;
    for (auto s : sup)
    {        
        
        if (adj[s.first][s.second] == 2)
            q.push_front(s);
        else
            q.push_back(s);
    }

    while (!q.empty())
    {
        int v1 = q.front().first, v2 = q.front().second;
        q.pop_front();

        for (int i = 0; i < 4; i++)
        {
            if (adj[v1 + lol[i].first][v2 + lol[i].second] == 0)
            {
                adj[v1 + lol[i].first][v2 + lol[i].second] =  adj[v1][v2]; 

                //parent[v1 + lol[i].first][v2 + lol[i].second] = {v1, v2};

                parent2[v1 + lol[i].first][v2 + lol[i].second] = lmao[i]; 
                q.push_back({v1 + lol[i].first, v2 + lol[i].second});        
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    vector<pair<int, int>> start;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;

            cin >> x;

            if (x == '.')
                adj[i][j] = 0;
            else if (x == 'A')
            {
                    adj[i][j] = 1;
                    start.push_back({i, j});
                    //parent[i][j] = {-1, -1};
            }
            else if (x == 'M') 
                start.push_back({i, j});                       
        }
    }

    bfs(start);

    /*
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= m+1; j++)
        {
            cout << adj[i][j];
        }
        cout << endl;
    }
    
    
    for (int i = 0; i <= n+1; i++)
    {
        for (int j = 0; j <= m+1; j++)
        {
            cout << parent2[i][j];
        }
        cout << endl;
    }
    */
    pair<int, int> h = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        if (adj[i][1] == 1)
        {
            h = {i, 1};
            break;
        }
        if (adj[i][m] == 1)
        {
            h = {i, m};
            break;
        }
    }

    for (int i = 2; i < m; i++)
    {
        if (adj[1][i] == 1)
        {
            h = {1, i};
            break;
        }
        if (adj[n][i] == 1)
        {
            h = {n, i};
            break;
        }
    }
    if (h.first == 0)
    {
        cout << "NO";
        return 0;
    }
    int v1 = h.first, v2 = h.second; 
    int len = 0;
    vector<char>road;

    while(parent2[h.first][h.second] != '0')
    {
        len++;
        road.push_back(parent2[h.first][h.second]);
        //h.first = parent[h.first][h.second].first;
        //h.second = parent[h.first][h.second].second;

        if (parent2[h.first][h.second] == 'U')        
            h.first += 1;
        else if (parent2[h.first][h.second] == 'D')
            h.first -= 1;
        else if (parent2[h.first][h.second] == 'R')
            h.second -= 1;
        else if (parent2[h.first][h.second] == 'L')
            h.second += 1;
        //cout << parent[h.first][h.second].first << ' ' << parent[h.first][h.second].second;
    }
    cout << "YES" << endl << len << endl;
    
    reverse(road.begin(), road.end());

    for (auto u : road)
        cout << u;
       
}