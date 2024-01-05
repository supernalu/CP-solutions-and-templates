#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

int a[MAXN];

int id[MAXN];

int res[MAXN];

set<int> s;

bool cmp(int c, int d)
{
    if (a[c] == a[d])
    {
        return d < c;
    }

    return a[c] < a[d];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        id[i] = i;     
    }

    s.insert(0);

    sort(id + 1, id + n + 1, cmp);

    for (int i = 1; i <= n; i++)
    {
        s.insert(id[i]);

        auto it = lower_bound(s.begin(), s.end(), id[i]);

        --it;

        res[id[i]] = *it;        
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }


}