#include <bits/stdc++.h>

using namespace std;

constexpr long long MOD = 1e9 + 7;

int n;

int main()
{
    cin >> n;

    long long res = 1;

    for (int i = 1; i <= n; i++)
    {
        res = (2*res)%MOD;
    }

    cout << res;
}