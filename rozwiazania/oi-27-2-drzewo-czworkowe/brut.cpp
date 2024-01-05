#include <bits/stdc++.h>

constexpr int MAXN = 1050;

using namespace std;

int m, n, k = -1;

int maxx, res;

string s;

bool vis[MAXN][MAXN];

pair<int, int> change[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void preprocessing(int x, int y, int size)
{
    k++;

    //cout << k << ": " << x << ' ' << y << ' ' << size << endl;

    if (s[k] == '4')
    {
        preprocessing(x, y, size/2);
        preprocessing(x + size/2, y, size/2);
        preprocessing(x, y + size/2 , size/2);
        preprocessing(x + size/2, y + size/2, size/2);
    }
    else
    {
        int w = s[k] - '0';

        for (int i = x; i < x + size; i++)
        {

            for (int j = y; j < y + size; j++)
                vis[i][j] = w;
        }
    }
}

int bfs(int startX, int startY)
{
    vis[startX][startY] = 0;

    queue<pair<int,int>> q;

    q.push({startX, startY});

    int size = 1;

    while (!q.empty())
    {
        int a = q.front().first, b = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int c = change[i].first, d = change[i].second;

            if (vis[a + c][b + d] == 1)
            {
                q.push({a+c, b+d});
                vis[a + c][b + d] = 0;
                size++;
            }
        }
    }

    return size;
}



int main()
{
    cin >> m;

    n = (1 << m);

    cin >> s;

    preprocessing(1, 1, n);


    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (vis[i][j] == 1)
            {
                res++;

                int tmp = bfs(i, j);

                maxx = max(tmp, maxx);
            }
        }   
    }

    cout << res << '\n' << maxx;    




    


}