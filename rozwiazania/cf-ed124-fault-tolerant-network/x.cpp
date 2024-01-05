#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int MAXN = 2e5 + 10;
 
int t;
 
int n;
 
long long a[MAXN], b[MAXN];
 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> t;
 
    while (t--)
    {
        cin >> n;
 
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
           cin >> b[i]; 
        }
 
        long long best[4];
 
        long long res = 0;
 
        vector<bool> done(4, 0);
 
        int tmp = 1e9;
 
        int id = 0;
 
        for (int i = 1; i <= n; i++)
        {
            if (max(b[1], a[i]) - min(b[1], a[i]) <= tmp)
            {
                tmp = max(b[1], a[i]) - min(b[1], a[i]);
 
                id = i;
            }
        }
        best[2] = tmp;
 
        tmp = 1e9;
 
        for (int i = 1; i <= n; i++)
        {
            if (max(b[n], a[i]) - min(b[n], a[i]) <= tmp)
            {
                tmp = max(b[n], a[i]) - min(b[n], a[i]);
 
                id = i;
            }
        }
        best[3] = tmp;
 
        
 
        tmp = 1e9;        
        
        for (int i = 1; i <= n; i++)
        {
        if (max(a[1], b[i]) - min(a[1], b[i]) <= tmp)
        {
            tmp = max(a[1], b[i]) - min(a[1], b[i]);
 
            id = i;
        }
        }
        
        best[0] = tmp;
 
        tmp = 1e9;
 
        
        for (int i = 1; i <= n; i++)
        {
        if (max(a[n], b[i]) - min(a[n], b[i]) <= tmp)
        {
            tmp = max(a[n], b[i]) - min(a[n], b[i]);
 
            id = i;
        }
        }
        best[1] = tmp;
 
        //cout << "           " << best[0] << ' ' <<  best[1] << ' ' << best[2] << ' ' << best[3] << '\n';
 
        cout << min({
            best[0] + best[1] + best[2] + best[3], 
            abs(a[n] - b[n]) + best[0] + best[2], 
            abs(a[1] - b[1]) + best[1] + best[3], 
            abs(a[1] - b[n]) + best[1] + best[2], 
            abs(a[n] - b[1]) + best[0] + best[3],
            abs(a[n] - b[n]) + abs(a[1] - b[1]), 
            abs(a[n] - b[1]) + abs(a[1] - b[n])} )
        <<'\n';
    }
}