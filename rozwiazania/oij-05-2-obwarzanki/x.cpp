#include<bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, m;

pair<int, int> obw[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> obw[i].first >> obw[i].second;
    }

    int res1 = 0, res2 = 0;

    pair<int, int> act = obw[m];

    for (int i = m + 1; i <= n; i++)
    {
        if (obw[i].first >= act.second or act.first >= obw[i].second)
            continue;


        
        res1++;
        act.first = min(obw[i].first, act.first);
        act.second = max(obw[i].second, act.second);
    }

    //cout << endl;

    act = obw[m];

    for (int i = m-1; i > 0; i--)
    {
        if (obw[i].first >= act.second or act.first >= obw[i].second)
            continue;


        //cout << i << ' ';
        res2++;
        act.first = min(obw[i].first, act.first);
        act.second = max(obw[i].second, act.second);
    }

    //cout << endl;

    cout << min(res1, res2);
}