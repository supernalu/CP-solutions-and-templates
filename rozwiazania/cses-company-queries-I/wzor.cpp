#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n, q;
vector<int> adj[MAXN];
int ancestor[20][MAXN];

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
}

int query(int a, int b)
{
    for (int i = 19; i >= 0; --i) 
    {
        if (b >= (1 << i)) 
        {
            b -= (1 << i);
            a = ancestor[i][a];
        }
    }
    return a;
}

int main()
{
    cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int a;

        cin >> a;

        ancestor[0][i] = a;
    }

    preprocessing();

    while (q--)
    {
        int a, b;

        cin >> a >> b;

        int res = query(a, b);

        cout << (res ? res : -1) << '\n';
    }
}