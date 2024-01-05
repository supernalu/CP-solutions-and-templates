#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second - a.first == b.second - b.first)
        return a.first < b.first;

    return a.second - a.first < b.second - b.first;
}

int x, n;
set<pair<int, int>, decltype(&cmp)> s(&cmp);
set<pair<int, int>> s2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> x >> n;
    s.insert({0, x});
    s2.insert({0, x});

    while (n--)
    {
        int a; cin >> a;

        auto it = s2.upper_bound({a, x+1});
        it--;
        pair<int, int> tmp = *it;
        s2.erase(it);
        s.erase(tmp);
        if (a >= tmp.first)
        {
            s.insert({tmp.first, a});
            s2.insert({tmp.first, a});
        }
        if (a <= tmp.second)
        {
            s.insert({a, tmp.second});
            s2.insert({a, tmp.second});
        }  
        /*
        for (auto u : s)
            cout << u.first << ' ' << u.second << ' ';
        cout << '\n';
        */

        tmp = *(s.rbegin());
        cout << tmp.second - tmp.first << ' ';
    }


}