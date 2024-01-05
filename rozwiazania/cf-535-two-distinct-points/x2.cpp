#include <bits/stdc++.h>

constexpr int INF = 1e9 + 10;

constexpr int MAXN = 1e5 + 20;

constexpr int MAXM = 310;

using namespace std;

int n, m;

int a[MAXN];

pair<int, int> seg[MAXM];

int maxi, maxID;

int res = 0;

vector<int> odt;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if (maxi < a[i])
        {
            maxi = a[i];

            maxID = i;
        }
    }   

    for (int i = 1; i <= m; i++)
    {
        cin >> seg[i].first >> seg[i].second; 
    }

    //sort(seg + 1, seg + m + 1);


    for (int i = 1; i <= n; i++)
    {
        int tmp = maxi - a[i];

        vector<int> used;

        for (int j = 1; j <= m; j++)
        {
            if (seg[j].first <= i && seg[j].second >= i)
            {
                used.push_back(j);

                tmp++;

                if (seg[j].first <= maxID && seg[j].second >= maxID)
                {
                    tmp--;
                }
            }
        }

        if (tmp > res)
        {
            res = tmp;

            odt = used;
        }
    }

    cout << res << endl << odt.size() << endl;

    for (auto i : odt)
    {
        cout << i << ' ';
    }

}