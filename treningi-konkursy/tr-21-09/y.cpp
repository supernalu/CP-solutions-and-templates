#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353;
constexpr int MAXN = 3e5 + 10;
int a[MAXN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1;  i <= n; i++)
    {
        cin >> a[i];
    }
    int res = 2;
    for (int i = 1; i+3 <= n+1; i+= 3)
    {
        sort(a+i, a+i+3);
        if (a[i] == a[i+2])
            res = (res*3)%MOD;
        else if (a[i] == a[i+1])
            res = (res*2)%MOD;
    }
    cout << res << '\n';
    
}