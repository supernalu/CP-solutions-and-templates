#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;

int n, m;

int matrix[110][110];

vector<vector<bool>> vis(MAXN, vector<bool>(MAXN, false));

void bfs(pair<int, int> st, int k)
{
    

    
    queue<pair<int, int>> q;

    q.push(st);

    bool bad = 0; 

    while (!q.empty())
    {
        int vX = q.front().first;
        int vY = q.front().second;

        if (vX == 0 || vX == m+1 || vY == 0 || vY == n+1)
        {
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    }

    




}