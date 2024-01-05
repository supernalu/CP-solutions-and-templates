#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

set <int> s;

int n, k;

int a[MAXN];

int res = 0;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];


    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (a[i]%k != 0)
        {
            res++;

            s.insert(a[i]);
            
            continue;
        }

        if (s.find(a[i]/k) == s.end())
        {
            res++;

            s.insert(a[i]);
        }
    }

    cout << res;

}