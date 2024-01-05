#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

int c[MAXN];

int l[MAXN];

int a[MAXN];

int il[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    int sum = 0;

    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];

        sum += c[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int a;

        cin >> a;

        l[a] = c[i];
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    

    if (sum > n)
    {
        cout << 0;

        return 0;
    }
    int off = 0;
    int res = 0;

    for (int i = 1; i <= sum; i++)
    {
        il[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (il[i] != l[i])
            off++;
    }

    if (off == 0)
        res++;

    for (int i = sum+1; i <= n; i++)
    {
        il[a[i]]++;

        if (il[a[i]] == l[a[i]])
            off--;
        else if (il[a[i]]-1 == l[a[i]])
            off++;

        il[a[i-sum]]--;

        if (il[a[i-sum]] == l[a[i-sum]])
            off--;
        else if (il[a[i-sum]]+1 == l[a[i-sum]])
            off++;

        if (off == 0)
            res++;
    }

    cout << res;




}