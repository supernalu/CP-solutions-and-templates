#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 210;

constexpr int INF = -1;

int n, m;

string name[MAXN];

int wsp[MAXN][MAXN];

int dp[10000][MAXN];

int suma;

int main()
{
    cin >> n >> m;

    for (int i = 1 ; i <= n; i++)
    {
        cin >> name[i];

        suma += name[i].length();
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                wsp[i][j] = 0;
                continue;
            }

            string a, b;

            for (int k = 0; k <= min(name[i].length(), name[j].length()); k++)
            {
                a = name[i][name[i].length() - 1 - k] + a;

                b = b + name[j][k];

                if (a == b)
                    wsp[i][j] = k+1;
            }
        }
    }

    unsigned int a = 10000;

    for (int i = 0; i <= min(m*name[1].length(), a); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }


    dp[0][0] = 0;

    for (int i = 0; i <= min(m*name[1].length(), a); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] == INF)
                continue;

            //cout << i << ' ' << j << endl;

            
            if (dp[i][j] >= m)
            {
                cout << i;

                return 0;
            }
            

            for (int k = 1; k <= n; k++)
            {
                //if (i + name[k].length() - wsp[j][k] == 5 and k == 2)
                //cout << i << ' ' << j << endl;

                dp[i + name[k].length() - wsp[j][k]][k] = max(dp[i + name[k].length() - wsp[j][k]][k], dp[i][j]+1);
            }
        }
    }
    /*

    for (int i = 0; i <= suma; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    } 
    */   
}