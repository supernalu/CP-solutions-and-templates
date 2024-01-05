#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;
constexpr int INF = 1e9 + 10;

int n, m, k;

int a[MAXN], b[MAXN];

vector<int> wh[MAXN];

bool res[MAXN];

int mini_res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1;  i <= n; i++)
    {
        cin >> a[i];

        wh[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    int j = 1;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[j])
        {

            mini_res[j] = i;

            res[i] = 1;

            j++;
        }
    }

    int maxi = INF;

    for (int i = m;  i > 0; i--)
    {
        int tmp = maxi;

        for (auto u: wh[b[i]])
        {
            //cout << u << ' ';

            if (u > mini_res[i] && u < maxi)
            {
                //cout << '!' << ' ';
                res[u] = 1;
                tmp = u;
            }
        }

        maxi = tmp;

        //cout << endl;
    }

    for (int i = 1;  i <= n; i++)
        cout << res[i] << ' ';

    
}