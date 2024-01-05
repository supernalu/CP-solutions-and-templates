#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5+10;
int n, q;
int a[MAXN];
int il[MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < MAXN)
            il[a[i]]++;
    }
    set<int> s;
    for (int i = 0; i <= n+1; i++)
        if (il[i] == 0)
            s.insert(i);
    while (q--)
    {
        int x, v; cin >> x >> v;
        if (a[x] < MAXN)
        {
            il[a[x]]--;
            if (il[a[x]] == 0)
                s.insert(a[x]);
        }
        
        a[x] = v;
        if (a[x] < MAXN)
        {
            il[a[x]]++;
            if (il[a[x]] == 1)
                s.erase(a[x]);
        }
        cout << *(s.begin()) << '\n';
    }

}