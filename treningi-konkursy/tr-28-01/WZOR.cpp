#include "cliclib.h"
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 30010;
long long n;
bool dp[MAXN][16][11][2];
int parent[MAXN][16][11][2];
int STOS = 0, POT2 = 0, POT3 = 0;
long long powerOfTwo[16], powerOfThree[11];

/*
int inicjuj()
{
    int k; cin >> k;
    return k;
}
*/




void preprocessing()
{
    dp[n][0][0][0] = 1;
    dp[n][0][0][1] = 0;

    int tmp = 1;
    for (int i = 0; i <= 15; i++)
    {
        powerOfTwo[i] = tmp;
        tmp*=2;
    }
    tmp = 1;
    for (int i = 0; i <= 10; i++)
    {
        powerOfThree[i] = tmp;
        tmp*=3;
    }


    for (int stos = n-1; stos >= 0; stos--)
    {
        for (int pot2 = 15; pot2 >= 0; pot2--)
        {
            for (int pot3 = 10; pot3 >= 0; pot3--)
            {
                for (int gracz = 0; gracz < 2; gracz++)
                {
                    if (powerOfThree[pot3]*powerOfTwo[pot2] + stos >= n)
                    {
                        dp[stos][pot2][pot3][gracz] = dp[n][0][0][(gracz+1)%2];
                        parent[stos][pot2][pot3][gracz] = 1;
                        continue;
                    }
                    if (gracz == 1)
                    {
                        dp[stos][pot2][pot3][gracz] = min({dp[min(n, stos+powerOfThree[pot3]*powerOfTwo[pot2])][0][0][(gracz+1)%2], dp[stos][pot2+1][pot3][(gracz+1)%2],  dp[stos][pot2][pot3+1][(gracz+1)%2]});
                        if (dp[min(n, stos+powerOfThree[pot3]*powerOfTwo[pot2])][0][0][(gracz+1)%2] == 0)
                            parent[stos][pot2][pot3][gracz] = 1;
                        if (dp[stos][pot2+1][pot3][(gracz+1)%2] == 0)
                            parent[stos][pot2][pot3][gracz] = 2;
                        if (dp[stos][pot2][pot3+1][(gracz+1)%2] == 0)
                            parent[stos][pot2][pot3][gracz] = 3;
                    }
                    else
                    {
                        dp[stos][pot2][pot3][gracz] = max({dp[min(n, stos+powerOfThree[pot3]*powerOfTwo[pot2])][0][0][(gracz+1)%2], dp[stos][pot2+1][pot3][(gracz+1)%2],  dp[stos][pot2][pot3+1][(gracz+1)%2]});
                        if (dp[min(n, stos+powerOfThree[pot3]*powerOfTwo[pot2])][0][0][(gracz+1)%2] == 1)
                            parent[stos][pot2][pot3][gracz] = 1;
                        if (dp[stos][pot2+1][pot3][(gracz+1)%2] == 1)
                            parent[stos][pot2][pot3][gracz] = 2;
                        if (dp[stos][pot2][pot3+1][(gracz+1)%2] == 1)
                            parent[stos][pot2][pot3][gracz] = 3;
                    }
                }
            }
        }
    }
    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 15; j++)
        {
            for (int h = 0; h < 11; h++)
            {
                for (int k = 0; k < 2; k++)
                    cout << parent[i][j][h][k] << "|";
                cout << " "; 
            }
            cout << '\n';
        }
        cout << '\n' << '\n';
    }
    */
    
}

int main()
{
    n = inicjuj();
    preprocessing();

    while (true)
    {
        int k = parent[STOS][POT2][POT3][0];
        alojzy(k);

        if (k == 1)
        {
            STOS = min(n, STOS + powerOfThree[POT3]*powerOfTwo[POT2]);
            POT2 = 0;
            POT3 = 0;
        }
        else if (k == 2)
        {
            POT2++;
        }
        else
        {
            POT3++;
        }
        if (STOS == n)
            break;
        
        k = bajtazar();

        if (k == 1)
        {
            STOS = min(n, STOS + powerOfThree[POT3]*powerOfTwo[POT2]);
            POT2 = 0;
            POT3 = 0;
        }
        else if (k == 2)
        {
            POT2++;
        }
        else
        {
            POT3++;
        }

        if (STOS == n)
            break;
    }   
}