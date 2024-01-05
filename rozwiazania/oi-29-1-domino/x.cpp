#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9 + 10;

long long  m;

unsigned long long fib[100];

int n = 2;

struct I
{
    int nt = INF;
};

map<long long, I> dp;




int mozna(long long wart, int j)
{
    /*
    if (wart == 1)
        return 0;
    */

    if (dp[wart].nt != INF)
        return dp[wart].nt;

    
    int res = INF;

    for (int i = j; fib[i] != 0; ++i)
    {       
        if (wart%fib[i])
            continue;
        
        res = min(res, mozna(wart/fib[i], i) + i + 1);
    }

    return dp[wart].nt = res;
    

}

int main()
{
    cin >> m;

    if (m == 1)
    {
        cout << 1;
        return 0;
    }

    fib[0] = 1;
    fib[1] = 1;    

    int maxi;

    for (int i = 2; fib[i-1] <= m; ++i)  
    {            
        fib[i] = fib[i-1] + fib[i-2];

        //cout << fib[i] << ' ';

        
    }

    dp[1] = I{0};

    int res = mozna(m, 2);

    if (res == INF)
        cout << "NIE";
    else
        cout << res - 1;

}