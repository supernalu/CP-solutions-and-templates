#include <bits/stdc++.h>

constexpr int MAXN = 2010;

using namespace std;

int n, k;

int a[MAXN];

bool cmp (int a, int b)
{
    return a > b;
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, cmp);

    int res = k;

    for (int i = k + 1; i <= n; i++)
    {
        if (a[i] != a[k])
            break;
        
        res++;
    }

    cout << res;
}