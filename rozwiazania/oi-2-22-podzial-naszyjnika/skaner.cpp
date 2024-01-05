#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e6 + 10;

int n, k;

int a[MAXN];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << n << ',' << k << '.';

    for (int i = 0; i < n; i++)
        cout << a[i] << ',';
}