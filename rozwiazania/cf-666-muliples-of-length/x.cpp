#include<bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 1e5 + 10;

ll n, a[MAXN];
ll seg1[MAXN], seg2[MAXN];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << "1 1\n" << -a[1] << '\n';

    if (n == 1)
    {
        cout << "1 1\n0\n1 1\n0\n";
        return 0;
    }

    seg2[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        seg1[i] = a[i];
        seg2[i] = -a[i];
    }

    cout << 2 << ' ' << n << '\n';
    for (int i = 2; i <= n; i++)
        cout << seg1[i]*(n-1) << ' ';
    cout << '\n';
    
    cout << 1 << ' ' << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << seg2[i]*n << ' ';


}