#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 3e5 + 10;
constexpr int INF = 1e8 + 10;
typedef long long ll;

ll n, t, k;
ll a[MAXN];
ll b[MAXN];

ll wave(int val,int st)
{
    ll val2 = val;
    ll res =  val2-a[st];

    for (int i = 1; i <= n; i++)
        b[i] = 0;

    b[st] = val2;
    b[n+1] = -INF;
    for (int i = st+1; i <= n; i++)
    {
        if (a[i]+1 < b[i-1])
        {
            res += b[i-1]-a[i]-1;
            b[i] = b[i-1]-1;
            if (i == n)
                res += 2*INF;
        }
        else
            break;
    }
    return res;
}


ll binSearch(int l, int r, int act)
{
    if (l == r)
        return l;
    int mid = (l+r+1)/2;
    //if (act == 1)
    //cout << l << ' ' << r  << ' '  << mid << ' ' << wave(mid, act)<< '\n';
    if (wave(mid, act) <= k)
        return binSearch(mid, r, act);
    else    
        return binSearch(l, mid-1, act);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxi = max(maxi, a[i]);
        }
        for (int i = 1; i < n; i++)
        {
            //cout << binSearch(a[i], 2*INF, i) << ' ';
            maxi = max(maxi, binSearch(a[i], 2*INF, i));
        }
        //cout << wave(7, 2) << ' ';
        
        cout << maxi << '\n';
    }
}