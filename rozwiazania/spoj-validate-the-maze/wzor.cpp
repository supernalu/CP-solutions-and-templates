#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 30;

int t;
int n, m;

bool vis[MAXN][MAXN];

void bfs(int s1, int s2)
{
    queue< pair<int,int> > lol;
    pair<int,int> pomo;
    pomo.first = s1; pomo.second = s2;
    lol.push(pomo);
    vis[s1][s2] = true;
    while (lol.size() != 0)
    {        
        if (vis[lol.front().first + 1][lol.front().second] == 0)
        {
            vis[lol.front().first + 1][lol.front().second] = true;
            pomo.first = lol.front().first + 1;
            pomo.second = lol.front().second ;
            lol.push(pomo);
        }
        if (vis[lol.front().first -1][lol.front().second] == 0)
        {
            vis[lol.front().first - 1][lol.front().second] = true;
            pomo.first = lol.front().first - 1;
            pomo.second = lol.front().second ;
            lol.push(pomo);
        }
        if (vis[lol.front().first ][lol.front().second + 1] == 0)
        {
            vis[lol.front().first][lol.front().second + 1] = true;
            pomo.first = lol.front().first ;
            pomo.second = lol.front().second + 1;
            lol.push(pomo);
        }
        if (vis[lol.front().first ][lol.front().second - 1] == 0)
        {
            vis[lol.front().first][lol.front().second - 1] = true;
            pomo.first = lol.front().first ;
            pomo.second = lol.front().second - 1;
            lol.push(pomo);
        }
        lol.pop();
    }

}


int main()
{
    cin >> t;

    for (int q = 0; q < t; q++)
    {
        cin >> n >> m;

        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                vis[i][j] = 1;
            }
        }
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char pom;
                cin >> pom;
                if (pom == '.')
                {
                    vis[i][j] = 0;
                }
            }
        }
        /*
        for (int i = 0; i <= n + 1; i++)
        {
            for (int j = 0; j <= m + 1; j++)
            {
                cout << vis[i][j] << ' ';
            }
            cout << endl;
        }
        */
        
        vector<pair <int, int>>wh;
        pair<int, int> pom;

        for (int i = 1; i <= n; i++)
        {
                if(vis[i][1] == 0)
                {
                    pom.first = i;
                    pom.second = 1;
                    wh.push_back(pom);
                }
                if (vis[i][m] == 0 && m != 1)
                {
                    pom.first = i;
                    pom.second = m;
                    wh.push_back(pom);
                }
        }
        for (int i = 2; i < m; i++)
        {
                if(vis[1][i] == 0)
                {
                    pom.first = 1;
                    pom.second = i;
                    wh.push_back(pom);
                }
                if (vis[n][i] == 0 && n != 1)
                {
                    pom.first = n;
                    pom.second = i;
                    wh.push_back(pom);
                }
        }

        if (wh.size() != 2)
        {
            cout << "invalid\n"; 
        }
        else 
        {
            bfs(wh[0].first, wh[0].second);
            if (vis[wh[1].first][wh[1].second] == true)            
                cout << "valid\n";            
            else 
                cout << "invalid\n";

        }
        


    }

}