#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int t, n;
long long a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] *= 10;
        }
        sort(a + 1, a + n + 1);
        long long res;
        if (n != 5)
            res = (a[n]+a[n-1])/2-(a[2]+a[1])/2;
        else
            res = max((a[n]+a[n-2])/2-(a[2]+a[1])/2, (a[n]+a[n-1])/2-(a[1]+a[3])/2);
        if (res%10 == 0)
            cout << "Case #" << Case << ": " << res/10 << '\n';
        else
            cout << "Case #" << Case << ": " << res/10 << ".5" << '\n';
    }
}