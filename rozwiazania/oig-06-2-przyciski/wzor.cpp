#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

int x[MAXN];

int maxi = 0;

int len = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;


    for (int q = 0; q < m; q++)
    {
        int p;

        cin >> p;

        if (p == n + 1)
        {
            len = maxi;
            continue;
        }

        if (x[p] < len)        
            x[p] = len;
               
        x[p]++;    

        if (x[p] > maxi)
            maxi = x[p];   
    }


    for (int i = 1; i <= n; i++)
    {
        if (x[i] < len)        
            x[i] = len;

        cout << x[i] << ' ';
    }


}

