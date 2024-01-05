#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int n, a[MAXN], res[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int st = n;
    for (int i = 1; i <= n; i+= 2)
    {
        res[i] = a[st];
        st--;
    }
    int wh;
    if (n%2)
        wh = n-1;
    else
    {
        res[n] = a[st];
        wh = n-2;
    }
    st = 1;
    int il = 0;
    for (int i = wh; i > 0; i-=2)
    {
        if (res[i-1] > a[st] && res[i+1] > a[st])
            il++;
        res[i] = a[st];
        st++;
    }
    cout << il << '\n';
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';


}