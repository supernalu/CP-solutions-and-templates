#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

long long a[MAXN];

long long il[MAXN];

int main()
{
    cin >> n;

    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];

        if (a[i] < 0)
        {
            int tmp = -a[i]/n;

            tmp++;

            a[i] += tmp*n;

            a[i] %= n;
        }

        a[i] += a[i-1];
        a[i] %= n;

        il[a[i]]++;
    }

    il[0]++;

    long long res = 0;

    for (int i = 0; i < n; i++)
    {
        res += (il[i]*(il[i]-1))/2;
    }

    cout << res;





}