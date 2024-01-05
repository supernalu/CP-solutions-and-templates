#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 10;
int t, n;
int a[MAXN], b[MAXN], id[MAXN], suf[MAXN];
bool cmp(int v, int u)
{
    if (a[v] == a[u])
        return b[v] < b[u];
    return a[v] < a[u];
}
bool cmp2(int v, int u)
{
    if (b[v] == b[u])
        return v < u;
    return b[v] < b[u];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            id[i] = i;
        }
        if (n == 1)
        {
            cout << abs(a[1]-b[1]) << '\n';
            continue;
        }
        sort(id+1, id+n+1, cmp);
        //for (int i = 1; i <= n; i++)
            //cout << id[i] << ' ';
        suf[n+1] = 0;
        for (int i = n; i > 0; i--)
            suf[i] = max(suf[i+1], b[id[i]]);
        
        //for (int i = n+1; i <= 2*n; i++)
            //b[i] = a[id[i-n]];
        set<int> s;
        int res = 1e9+10;
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            if (n != i)
                tmp = abs(a[id[i]]-suf[i+1]);
            else
                tmp = 2e9 + 10;
            //cout << tmp << ' ';
            if (i == 1 || suf[i+1] > a[id[i]])
            {
                res = min(res, tmp);
                s.insert(b[id[i]]);
                continue;
            }
            auto it = s.lower_bound(a[id[i]]);
            //cout << s.size() << ' '; 
            if (it != s.end())
            {
                //cout << *it << ' ';
                tmp = min(tmp, abs(a[id[i]]-*it));
                //cout << *it;
                //cout << tmp << ' ';
            }
            if (it !=s.begin())
            {
                --it;
                //cout << *it << '\n';
                tmp = min(tmp, abs(a[id[i]]-*it));
                //cout << tmp << ' ';
            }
            res = min(res, tmp);
            s.insert(b[id[i]]);
            
        }
        cout << res << '\n';
    }
}