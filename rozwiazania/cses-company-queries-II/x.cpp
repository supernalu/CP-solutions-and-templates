#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n, q;

int ancestor[20][MAXN];

int degree[MAXN];

void preprocessing()
{
    ancestor[1][0] = 0;

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ancestor[i][j] == 0)
                ancestor[i][j] = 1;
        }
    }
}

void query(int a, int b)
{
    if (degree[a] > degree[b])
        swap(a, b);

    int r = degree[b] - degree[a];

    for (int i = 19; i >= 0; i--)
    {
        if (r >= (1 << i))
        {
            r -= (1 << i);

            b = ancestor[i][b];
        }
    }

    if (a == b)
    {
        cout << a << '\n';

        return;
    }

    for (int i = 19; i >= 0; i--)
    {
        if (ancestor[i][a] != ancestor[i][b])
        {
            a = ancestor[i][a];
            b = ancestor[i][b];
        }
    }

    cout << ancestor[0][a] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    degree[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        cin >> ancestor[0][i];

        degree[i] = degree[ancestor[0][i]] + 1;
    }

    preprocessing();


    while (q--)
    {
        int a, b;

        cin >> a >> b;

        query(a, b);
    }


    
}