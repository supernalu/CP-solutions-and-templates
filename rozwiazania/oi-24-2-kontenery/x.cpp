#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

constexpr int SQRT = 3e2 + 30;

int n, q;

int res[MAXN];

int pref[SQRT][MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    int s = sqrt(n);

    while (q--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        if (c <= s)
        {
            pref[c][a]++;

            pref[c][min(a + b*c, n+1)]--;
        }
        else
        {
            for (int i = a; i <= a + (b-1)*c; i += c)
                res[i]++;  
        }
    }
    

    for (int j = 1; j <= s; j++)
    {
        for (int k = 1; k <= j; k++)
        {
            for (int i = k; i <= n; i += j)
            {
                pref[j][i] += pref[j][max(0, i - j)];               
            }  
        }
    }

    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res[j] += pref[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }

    
    


}