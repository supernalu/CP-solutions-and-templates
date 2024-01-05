#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 10;

int n;

vector<pair<int, int>> dom;

vector<int> diff;

int m1, m2;

int h1, h2;

int h, m;

vector<int> used(MAXN, 0);

int solve()
{
    int r = 1;

    double tmp = diff[r]/h;

    int res = 0;
    int t;

    for (int l = 0; l < n; l++)
    {
        t = r - l - 1;

        m += used[l];

        if (r <= l)
            r = l+1;

        tmp = diff[r]/h;

        while (ceil(tmp) <= m && r < n)
        {
            used[r] = ceil(tmp);

            r++;

            m -= ceil(tmp);

            t++;

            tmp = diff[r]/h;

            
        }

        //cout << l <<  ' ' << r << endl;

        res = max(res, t);
    }

    return res;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b;

        cin >> a >> b;

        dom.push_back({a, b});
    }

    cin >> m1 >> h1 >> m2 >> h2;

    diff.push_back(0);


    
    for (int i = 0; i < n-1; i++)
    {
        diff.push_back(max(dom[i+1].first - dom[i].first - dom[i].second, 0));
    }
    

    diff.push_back(-1);

    int res = 0;

    if (h1 == h2)
    {
        h = h1;

        m= m1 + m2;

        res = solve();

        reverse(diff.begin(), diff.end());

        res = max(res, solve());

        cout << res + 1 + m;
    }
}