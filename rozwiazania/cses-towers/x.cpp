#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

constexpr int INF = 1e9;

int n;

vector<int> s;

int a[MAXN];

int res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    s.push_back(a[1]);
    res = 1;

    for (int i = 2; i <= n; i++)
    {
        auto it = upper_bound(s.begin(), s.end(), a[i]);

        if (it == s.end())
        {
            res++;
            s.push_back(a[i]);
            continue;
        }

        *it = a[i];
    }

    cout << res;
}