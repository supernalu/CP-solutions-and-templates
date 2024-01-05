#include <bits/stdc++.h>
constexpr int MAXN = 3e5 + 10;
using namespace std;
int t, n;
long long a[MAXN];
long long maxi;
long long solve(int nwd)
{
    //cout << nwd;
        long long res = 0;
        vector<long long> tmp;
        for (int i = 1; i <= n; i++)
        {
            res += (maxi-a[i])/nwd;
            tmp.push_back((maxi-a[i])/nwd);
            //cout <<  (maxi-a[i])/nwd << ' ';
        }
        //cout << res << ' ';
        long long res2 = res+n;
        sort(tmp.begin(), tmp.end());
        tmp.push_back(1e9 + 10);
        bool done = 0;
        for (int i = 0; i < tmp.size()-1; i++)
        {
            if (tmp[i]+1 < tmp[i+1])
            {
                done = 1;
                res += tmp[i]+1;
                break;
            }
        }
        //cout << res << ' ' << res2 << ' ';
        return min(res, res2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxi = max(maxi, a[i]);
        }
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        //cout << "done";
        long long nwd = maxi-a[1];
        //cout << "done";
        for (int i = 1; i <= n; i++)
        {
            //if (a[i] == maxi)
                //continue;
            nwd = __gcd(maxi-a[i], nwd);
            //cout << "done";
        }
        long long res = 1e18+10;
        for (int i = 1; i*i <= nwd; i++)
        {
            if (nwd%i != 0)
                continue;
            res = min(res, solve(nwd/i));
            res = min(res, solve(i));
        }
        cout << res << '\n';

        

    }
}