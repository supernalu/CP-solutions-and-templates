#include <bits/stdc++.h>

constexpr int MAXN = 2e5 + 10;

using namespace std;

int n, m;

long long x[MAXN];

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];

        x[i] += x[i-1];
    }

    for (int i = 1; i <=m; i++)
    {
        int a, b;

        cin >> a >> b;

        cout << x[b] - x[a-1] << endl;
    }


}