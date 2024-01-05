#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int n;
pair<int, int> range[MAXN];
int id[MAXN];
bool res1[MAXN], res2[MAXN];

bool cmp(int a, int b)
{
    if (range[a].first == range[b].first)
        return range[a].second > range[b].second;
    return range[a].first < range[b].first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> range[i].first >> range[i].second;
        id[i] = i;
    }

    int mini = 1e9 + 10;
    for (int i = n; i > 0; i--)
    {
        if (mini <= range[id[i]].second)
            res1[id[i]] = 1;
        else
            res1[id[i]] = 0;
        mini = min(mini, range[id[i]].second);
    }
    for (int i = 1; i <= n; i++)
        cout << res1[i] << ' ';
    cout << '\n';

    int maxi = 0;
    for (int i = 1;  i <= n; i++)
    {
        if (maxi >= range[id[i]].second)
            res2[id[i]] = 1;
        else
            res2[id[i]] = 0;
        maxi = max(maxi, range[id[i]].second);
    }
    for (int i = 1; i <= n; i++)
        cout << res2[i] << ' ';


    
}