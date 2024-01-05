#include <bits/stdc++.h>
using namespace std;
int n;
long long a[510];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
            for (int k = 1; k <= n; k++)
                res = max(res, a[i] | a[j] | a[k]);
    cout << res;
        
    
}