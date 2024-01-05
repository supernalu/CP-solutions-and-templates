#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;

int t, n, a[MAXN];

int check(int k)
{
    int res = 0, maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > maxi)
        {
            res++;
            maxi = a[i] + 2*k;
        }
    }
    return res;
}
int binSearch(int l, int r)
{
    if (l == r)
        return l;
    int mid = (l+r)/2;
    if (check(mid) <= 3)
        return binSearch(l, mid);
    else
        return binSearch(mid+1, r);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        cout << binSearch(0, 1e9 + 10) << '\n';
    }
}