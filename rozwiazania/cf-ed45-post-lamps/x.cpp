#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, m, k;
bool blocked[MAXN];
int last[MAXN];
long long cost[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    while (m--)
    {
        int tmp; cin >> tmp;
        blocked[tmp] = 1;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> cost[i];
    }
    if (blocked[0])
    {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {   
        if (blocked[i])
            last[i] = last[i-1];
        else
            last[i] = i;
       // cout << last[i] << ' ';
    }
    long long res = 1e18 + 10;
    for (int i = 1; i <= k; i++)
    {
        int act = 0;
        long long tmp = 0;
        while (true)
        {
            //cout << act << ' ';
            int old = act;
            tmp += cost[i];
            act = min(n, act + i);
            if (act == n)
                break;
            act = last[act];
            
            if (act == old)
            {
                tmp = 1e18 + 10;
                break;
            }
        }
        //cout << tmp << '\n';
        res = min(res, tmp);
    }
    if (res == 1e18+10)
        cout << "-1";
    else
        cout << res;

}