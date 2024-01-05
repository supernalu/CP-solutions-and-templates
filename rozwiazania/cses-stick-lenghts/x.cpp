#include <bits/stdc++.h>

using namespace std;

int n;

constexpr int MAXN = 2e5 + 10;

int a[MAXN];

long long res = 0;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int med = a[(n+1)/2];

    for (int i = 1; i <= n; i++)
    {
        res += max(med, a[i]) - min(med, a[i]);
    }

    cout << res;
}