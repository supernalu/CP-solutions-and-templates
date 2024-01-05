#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 2e5 + 10;


int t, n;
int a[MAXN];

int solve(int l, int r)
{
    if (l == r)
    {
        return l;
    }
    bool res = 1;
    int mid = (l+r)/2;

    int tmp = mid;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= mid || a[i] >= n+1-mid)
            continue;
        

        if (a[i] == tmp+1)
            tmp++;
        else
            res = 0;
    }
    

    if (res)
        return solve(l, mid);
    else    
        return solve(mid+1, r);

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

        cout << solve(0, n/2) << '\n';
    }
}