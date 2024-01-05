#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000005;

int n, m;

int p[MAXN];

int wh[MAXN];

int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    wh[0] = 0;
    int k = 1;
    for (int i = 1; i <= m; i++)
    {
        
        cin >> p[i];
        if (p[i] == n+1)
        {
            wh[k] = i;
            k++;
        }
    }
    /*
    for (int i = 0; i < k; i++)    
       cout << wh[i] << ' ';    
    cout << endl;
    */
    int v = 0;
    for (int i = 1; i < k; i++)
    {
        sort(p + wh[i-1] + 1, p + wh[i] - 1);
        int il = 1;
        int max_il = 1;
        for (int j = wh[i-1] + 2; j <= wh[i] - 1; j++)
        {
            if (p[j] == p[j-1])
            {
                il++;
            }
            else 
            {
                il = 1;
            }
            if (il > max_il)
            {
                max_il = il;
            }
        }
        v += max_il;
    }
    for (int i = 1; i <= n; i++)
    {
        res[i] += v;
    }
    for (int i = wh[k-1]+1; i <= m; i++)
    {
        res[p[i]]++;
    
    }
    /*
    for (int i = 1; i <= m; i++)
    {
        cout << p[i] << ' ';
    }
    cout << endl;
    */
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;

}