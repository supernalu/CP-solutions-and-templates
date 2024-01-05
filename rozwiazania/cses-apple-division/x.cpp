#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a[30];

int n;

ll solve(ll d, ll b, int c)
{
    if (c == n+1)
    {
        return  max(d, b) - min(d, b);
    }
    
    //cout << d << ' ' << b << endl;

    return min(solve(d + a[c], b, c+1), solve(d, b + a[c], c+1));
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << solve(0, 0, 1);
}