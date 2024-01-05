#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n, q;

int x[MAXN];

int main()
{
    cin >> n >> q;

    x[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];

        x[i] = x[i] xor x[i-1];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;

        cin >> a >> b;

        int res = x[b] xor x[a-1];

        cout << res << endl;

    }

}