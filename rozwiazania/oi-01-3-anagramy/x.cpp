#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3100;

int n;

pair<string, string> a[MAXN];

bool cmp(pair<string, string> b, pair<string, string> c)
{
    if (b.second == c.second)
    {
        return b.first < c.first;
    }
    return b.second < c.second;
}

bool cmp2(int c, int b)
{
    return a[c].first < a[b].first;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        string x;

        cin >> x;

        a[i].first = x;

        sort(x.begin(), x.end());

        a[i].second = x;
    }

    sort(a + 1, a + n + 1, cmp);

    vector<int> biblio;

    biblio.push_back(1);


    for (int i = 2; i <= n; i++)
    {
        if (a[i].second != a[i-1].second)
        {
            biblio.push_back(i);
        }
    }

    sort(biblio.begin(), biblio.end(), cmp2);


    for (auto j : biblio)
    {
        cout << a[j].first << ' ';

        int k = j+1;

        while (k <= n && a[j].second == a[k].second)
        {
            if (a[k].first != a[k-1].first)
                cout << a[k].first << ' ';
            k++;
        }

        cout << '\n';
    }



}