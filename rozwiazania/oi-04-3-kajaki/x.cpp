#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e4 + 10;

int n, w;

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> w >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int L = 1, R = n, res = 0;

    while (L <= R)
    {
        
        res++;

        if (a[R] + a[L] <= w)
        {
            R--;
            L++;
        }
        else
        {
            R--;
        }
    }

    cout << res;
}
