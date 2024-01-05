#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

int f[MAXN], w[MAXN];

vector <int> wh[MAXN];

struct comp
{
    int L;

    int R;

    int maxi;

    int lazy;

};

int k[MAXN];

int x[MAXN];

int sq[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> f[i];  

    for (int i = 1; i <= m; i++)
        cin >> w[i];
    

    for (int i = 1; i <= n; i++)
        wh[f[i]].push_back(i);
    
    for (int i = 1; i <= m; i++)
        wh[i].push_back(n+1);

    for (int i = 1; i <= m; i++)
    {
        if (wh[i].size() != 1)
        {
            x[wh[i][0]] += w[i];

            x[wh[i][1]] -= w[i];
        }
    }
    
    
}