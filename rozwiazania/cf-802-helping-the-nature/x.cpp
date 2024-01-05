#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
long long a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long res = 0, li = a[n];
        for (int i = 1; i < n; i++)
        {
            long long tmp = a[i]-a[i+1];
            res += abs(tmp);
            if (tmp < 0)
                li += tmp;
        }
        cout << res + abs(li) << '\n';
    }
}