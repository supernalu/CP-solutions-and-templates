#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, k;

int m, l;

int a[MAXN];

vector<int> il[MAXN];

int x[MAXN], y[MAXN];

bool done[MAXN];

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        il[a[i]].push_back(i);
    }

    cin >> m >> l;

    for (int i = 1; i <= m; i++)
        cin >> x[i];

    for (int i = 1; i <= l; i++)
        cin >> y[i];

    int r = 0;

    set<int> res;

    for (int i = 1; i < n; i++)
    {
        if (done[a[i]] == 0 && il[a[i]][il[a[i]].size()-1] > r)
        {

            r = il[a[i]][il[a[i]].size()-1];

            //cout << i << ' ' << r << endl;

            done[a[i]] = 1;

            int L = 1, R = 1, w1 = 0, w2 = 0;
            if (m != 1)
            {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] == x[L])
                {              
                    L++;

                    if (L == m)
                    {
                        w1 = j;
                        break;
                    }
                }
            }
            }
            else
                w1 = i;

            if (w1 == 0)
                continue;

            
            if (l != 1)
            {
            for (int j = r - 1; j > 0; j--)
            {
                if (a[j] == y[R])
                {
                    R++;

                    if (R == l)
                    {
                        w2 = j;
                        break;
                    }
                }
            }
            }
            else
                w2 = r;

            //cout << w2 << ' ';

            if (w2 == 0 || w1 >= w2)
                continue;

            for (int j = w1 + 1; j < w2; j++)
            {
                if (a[j] == x[m])
                    res.insert(j);
            }
        }
    }

    cout << res.size() << '\n';

    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << ' ';

}