#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 25010;

int t;
int n, m, stX, stY, edX, edY;
string kierunek;

vector<vector<int>> dp[2][2]; 

void init()
{
    dp[0][0].resize(n+10); dp[1][0].resize(n+10); dp[0][1].resize(n+10); dp[1][1].resize(n+10); 

    for (int i = 1; i <= n; i++)
    {
        dp[0][0][i].resize(m+10); dp[1][0][i].resize(m+10); dp[0][1][i].resize(m+10); dp[1][1][i].resize(m+10);
        for (int j = 1; j <= m; j++)
            for (int k1 = 0; k1 < 2; k1++)
                for (int k2 = 0; k2 < 2; k2++)
                    dp[k1][k2][i][j] = 1e9;  
    } 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> stX >> stY >> edX >> edY >> kierunek;
        init();

        //cout << 'l';

        int k1, k2;
        if (kierunek[0] == 'U')
            k1 = 1;
        else 
            k1 = 0;

        if (kierunek[1] == 'R')
            k2 = 1;
        else 
            k2 = 0;

        dp[k1][k2][stX][stY] = 0;
        int st = 0;

        while (true)
        {
            bool bounce = 0;
            if (k1 == 1 &&  stX == 1)
            {
                k1 = 0;      
                bounce = 1;
            }
            else if (k1 == 0 && stX == n)
            {
                k1 = 1;      
                bounce = 1;
            }

            if (k2 == 1 &&  stY == m)
            {
                k2 = 0;   
                bounce = 1;
            }
            else if (k2 == 0 && stY == 1)
            {
                k2 = 1;
                bounce = 1;
            }
            if (bounce)
            {
                st++;
                if (dp[k1][k2][stX][stY] != 1e9)
                    break;
            }

            

            if (k1 == 1)
                stX -= 1;
            else
                stX += 1;
            
            if (k2 == 0)
                stY -= 1;
            else
                stY += 1;

            //cout << stX << ' ' << stY << '\n';

            if (dp[k1][k2][stX][stY] != 1e9)
                break;
            
            dp[k1][k2][stX][stY] = st;
        } 
        int mini = min({dp[0][0][edX][edY], dp[0][1][edX][edY], dp[1][0][edX][edY], dp[1][1][edX][edY]});

        if (mini == 1e9)
            cout << -1 << '\n';
        else 
            cout << mini << '\n';
    }

    
}