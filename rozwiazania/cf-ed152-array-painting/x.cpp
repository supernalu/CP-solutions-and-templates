#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n, a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    t = 1;
    while (t--)
    {
        cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        a[n+1] = 0;
        for (int i = 1; i <= n; i++)
            if (a[i-1] == 0 && a[i] == 0 && a[i+1] == 0)
                res++;
        a[n+1] = 2;
        a[n+2] = 0;
        int size = 1, isTwo = 1;
        for (int i = 1; i <= n+2; i++)
        {
            if (a[i] == 0)
            {
                if (size == 1)
                    continue;
                if (isTwo)
                    res++;
                else
                    res+=2;
                size = 1;
                isTwo = 0;
                cout << res << ' ';
            }
            else if (a[i] == 2)
            {
                isTwo = 1;
                size++;
            }
            else
                size++;
            if (i == n && a[n] == 0)
                break;
            
        }
        cout << res;
    }
}