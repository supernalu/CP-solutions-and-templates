#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1e5 + 10;
int t, n, m, q;
pair<int, int> segment[MAXN];
int query[MAXN];
int pref[MAXN];

bool check(int k)
{
    for (int i = 0; i <= n; i++)
        pref[i] = 0;
    for (int i = 1; i <= k; i++)
            pref[query[i]] = 1; 
    for (int i = 1; i <= n; i++)
        pref[i] += pref[i-1];
    for (int i = 1; i <= m; i++)
    {
        int r = segment[i].second, l = segment[i].first;

        if (pref[r]-pref[l-1] > (r-l+1)/2)
            return 1;
    }
    return 0;  
}

int binSearch(int l, int r)
{
    int mid = (l+r)/2;

    if (l == r)
        return l;
    if (check(mid))
        return binSearch(l, mid);
    return binSearch(mid+1, r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        for (int i = 1;  i <= m; i++)
            cin >> segment[i].first >> segment[i].second;
        cin >> q;
        for (int i = 1; i <= q; i++)
            cin >> query[i];
        
        if (binSearch(1,q+1) == q+1)
            cout << "-1\n";
        else
            cout << binSearch(1, q+1) << '\n';
    }
}