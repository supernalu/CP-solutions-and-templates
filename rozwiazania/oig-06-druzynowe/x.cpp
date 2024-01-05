#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n;
int a[MAXN], id[MAXN];

vector<int> wh[MAXN];

bool cmp(int c, int b)
{
    return a[c] < a[b];
}

int main()
{
   cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }

    sort(id+1, id+n+1, cmp);

    

    int k = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[id[i]] != a[id[i+1]])
        {
            a[id[i]] = k;
            k++;
        }
        else
            a[id[i]] = k;
    }

    a[id[n]] = k;

    for (int i = 1; i <= n; i++)
    {
        wh[a[i]].push_back(i);
    }

    int res = 1e9 + 10;

    for (int i = 0; i < n; i++)
    {
        if (wh[i].size() < 3)
            continue;

        for (int j = 0; j < wh[i].size()-2; j++)
        {
            
            res = min(res, wh[i][j+2]-wh[i][j]+1);
        }
    }

    if (res == 1e9 +10)
        cout << "NIE";
    else
        cout << res;

    

    
    
}