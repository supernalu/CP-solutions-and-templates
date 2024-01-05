#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n, m;

int t;

multiset<int> h;

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;

        h.insert(j);
    }
    
    for (int i = 1; i <= m; i++)
    {
        cin >> t;

        auto it = h.upper_bound(t);
        if (it == h.begin())
        {
            cout << -1 << endl;
            continue;
        }
        it--;

        if(*it > t)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            cout << *it << endl;
            h.erase(it);
        }
    }


    
}