#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, t;

int a[MAXN];

int main()
{
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int sum = 0, r = 1;

    int res = 0;

    int tmp = 0;

    for (int l = 1; l <= n; l++)
    {
        r = max(l, r);
       
        while(sum + a[r] <= t && r <= n)
        {
            sum += a[r];
            tmp++;

            r++;

            
  
        }
        
        res = max(res, tmp);

        sum -= a[l];


        sum = max(sum, 0);

        tmp--;

        tmp = max(tmp, 0);
    }

    cout << res;
}