#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6;

int n;

int a[MAXN];


int main()
{
    cin >> n;

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        cout << (a[i] xor a[i-1]) << ' ';
    }

    //cout << res;
}

