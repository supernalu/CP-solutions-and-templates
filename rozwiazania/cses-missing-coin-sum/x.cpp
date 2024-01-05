#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

long long a[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    long long maxi = 0;

    for (int i = 1; i <= n; i++)
    {
        if (maxi + 1 < a[i])
        {
            cout << maxi + 1;

            return 0;
        }

        maxi += a[i];
    }

    cout << maxi + 1;
}