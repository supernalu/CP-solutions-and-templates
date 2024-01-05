#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int n, a[MAXN];
int last[MAXN];
bool vis[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        last[a[i]] = i;
    int res = 0;
    int j, act;
    for (int i = 1; i <= n; i++)
    {
        if (last[a[i]] == i || vis[a[i]] == 1)
            continue;
        vis[a[i]] = 1;
        act = last[a[i]];
        res += last[a[i]]-i-1;
        int start = i+1;
        int newAct;
        //cout << res << '\n';
        while (true)
        {
            newAct = act;
            for (j = start; j < act; j++)
            {
                if (vis[a[j]])
                    continue;
                vis[a[j]] = 1;
                if (last[a[j]] < act)
                    continue;
                newAct = max(newAct, last[a[j]]);
                //res += last[a[j]]-act-1;
                //act = last[a[j]];
                //cout << res << ' ';
            }
            if (newAct > act)
                res += newAct-act-1;
            else
                break;
            start = act+1;
            act = newAct;
        }
        i = act;
    }
    cout << res << '\n';
}