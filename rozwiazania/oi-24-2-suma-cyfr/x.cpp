#include <bits/stdc++.h>

using ll = long long;
using namespace std;
constexpr int MAXN = 210;

int s, m, q;
ll dp[MAXN][MAXN][MAXN];
int pot[MAXN];


void preprocessing()
{
    pot[0] = 1;

    for (int i = 1; i <= 200; i++)
        pot[i] = (10*pot[i-1])%m;

    dp[0][0][0] = 1;

    for (int dl = 0; dl <= 200; dl++)
    {
        for (int mod = 0; mod < m; mod++)
        {
            for (int suma = 0; suma <= s; suma++)
            {
                if (dp[dl][mod][suma] > (ll)1e18 || dp[dl][mod][suma] == -1)
                {
                    dp[dl][mod][suma] = -1;

                    for (int i = 0; i <= 9; i++)
                    {
                        if (suma+i > s)    
                            continue; 
                        dp[dl+1][(10*mod + i)%m][suma+i] = -1;
                    }
                    continue;
                }

                for (int i = 0; i <= 9; i++)
                {
                    if (suma+i > s)    
                        continue; 
                    if (dp[dl+1][(10*mod + i)%m][suma+i] == -1 || dp[dl+1][(10*mod + i)%m][suma+i] + dp[dl][mod][suma] > 1e18)
                        dp[dl+1][(10*mod + i)%m][suma+i] = -1;
                    else
                        dp[dl+1][(10*mod + i)%m][suma+i] += dp[dl][mod][suma];
                }
            }
        }
    }
}

int findLength(ll k)
{
    for (int i = 1; i <= 200; i++)
        if (dp[i][0][s] >= k || dp[i][0][s] == -1)        
            return i;  
    return -1;
}

int findDigit(int dl, int &mod, int &sum, ll &k)
{
    for (int i = 0; i <= 9; i++)
    {
        //cout << dl << ' ';
        //cout << (mod-pot[dl]*i+m*1000)%m << ' ';
        //cout << sum - i << endl;
        if (dp[dl][(mod-pot[dl]*i+m*1000)%m][sum-i] >= k)
        {
            mod = (mod-pot[dl]*i+m*1000)%m;
            sum -= i;
            return i;
        }
        k-= dp[dl][(mod-pot[dl]*i+m*1000)%m][sum-i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> m >> q;

    preprocessing();

    while (q--)
    {
        ll k; cin >> k;
        
        
        if (k > dp[200][0][s] && dp[200][0][s] != -1)
        {
            cout << "NIE\n";
            continue;
        }
        int n = findLength(k);
        if (n == -1)
        {
            cout << "NIE\n";
            continue;
        }
        vector<int> res; 
        int mod = 0, suma = s;
        while (n--)
            res.push_back(findDigit(n, mod, suma, k));

        for (auto i : res)
            cout << i;
        cout << '\n';
    }
}