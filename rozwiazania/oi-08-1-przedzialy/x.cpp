#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n;

pair<int, int> a[MAXN];

vector<pair<int, int>> res;

/*
bool cmp(pair<int, int> b, pair<int, int> c)
{
    if (b.first == c.first)
        return b.second < c.second;
    
    return b.first < c.first;
}
*/

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int c, b;

        cin >> c >> b;

        a[2*i-1] = {c, 0};
        a[2*i] = {b, 1};
    }

    sort(a + 1, a + 2*n + 1);

    int il = 0;

    pair<int, int> tmp;

    for (int i = 1; i <= 2*n; i++)
    {
        if (a[i].second == 0)
            il++;
        else
            il--;

        //cout << il << ' ';

        if (il == 1 && a[i].second == 0)
        {
            tmp.first = a[i].first;
        }
        else if (il == 0)
        {
            tmp.second = a[i].first;

            res.push_back(tmp);
        }
    }

    for (auto i : res)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
    
    
}