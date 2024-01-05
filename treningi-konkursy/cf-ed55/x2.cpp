#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, m;

vector <int> a[MAXN];

vector<bool> used(MAXN, 1);

int res;

int sum[MAXN];

bool cmp(int c, int d)
{
    return c > d;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int c, b;

        cin >> c >> b;

        a[c].push_back(b);
    }

    for (int i = 1; i <= m; i++)
    {
        sort(a[i].begin(), a[i].end(), cmp);
    }

    for (int j = 1; j <= m; j++)
    {
        if (a[j].size() > 0)
            sum[0] += max(0, a[j][0]);

        for (int i = 1; i < a[j].size(); i++)
        {
            a[j][i] += a[j][i-1];

            if (a[j][i] < 0)
                a[j][i] = 0;

            sum[i] += a[j][i];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        res = max(res, sum[i]);
    }

    cout << res;





    






}