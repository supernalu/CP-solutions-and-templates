#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n;

int a[MAXN];

int main()
{
    cin >> n;

    int res = 0, mini = 1e9 + 10;;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        mini = min(mini, a[i]);

        res = max(res, a[i] - mini);
    }

    cout << res;
}