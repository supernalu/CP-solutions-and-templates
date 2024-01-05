#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

int q;

long long a[MAXN];

long long pref[MAXN];

int main()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    while (q--)
    {
        int c, d;

        cin >> c >> d;

        pref[c]++;

        pref[d+1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        pref[i] += pref[i-1];
    }

    sort(pref + 1, pref + n + 1);

    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += pref[i]*a[i];
    }

    cout << sum;



}