#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 110;

int t;

int n;

int a[MAXN];

int res[MAXN];

void solve(int d, int b, int c)
{
    if (d > b)
        return;
    

    int maxi = 0;
    int id = 0;

    for (int i = d; i <= b; i++)
    {
        if (a[i] > maxi)
        {
            maxi = a[i];

            id = i;
        }
    }

    res[id] = c;

    solve (d, id-1, c+1);
    solve (id+1, b, c+1);
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];

            res[i] = 0;
        }

        solve(1, n, 0);

        for (int i = 1; i <= n; i++)
        {
            cout << res[i] << ' ';
        }

        cout << endl;

    }
}