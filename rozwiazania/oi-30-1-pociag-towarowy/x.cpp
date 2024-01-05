#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 3e5 + 10;
constexpr int INF = 1e9 + 10;

int n, m, k;

int a[MAXN], b[MAXN];

queue<int> wh[MAXN];

bool res[MAXN];

int mini_res[MAXN], maxi_res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1;  i <= n; i++)
    {
        cin >> a[i];

        //cout << i << ' ';

        wh[a[i]].push(i);
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

            j++;

            res[i] = 1;
        }
    }
    j = m;

    for (int i = n; i > 0; i--)
    {
        if (a[i] == b[j])
        {

            maxi_res[j] = i;

            j--;

            res[i] = 1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        while(!wh[b[i]].empty() && wh[b[i]].front() < maxi_res[i])
        {
            if (wh[b[i]].front() > mini_res[i])
            {
                res[wh[b[i]].front()] = 1;
            }

            wh[b[i]].pop();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
    
}