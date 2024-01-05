#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
long long a[MAXN];
pair<long long, long long> pref[MAXN];
long long diff[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        diff[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i-1];
            if (i%2)
                pref[i].first += a[i];
            else
                pref[i].second += a[i];
            diff[i] = pref[i].second-pref[i].first;
        }
        //for (int i = 1; i <= n; i++)  {
            //cout << pref[i].first << ' ' << pref[i].second << '\n';
        //}
        sort(diff, diff+n+1);
        bool res = 0;
        for (int i = 0; i < n; i++)
            if (diff[i] == diff[i+1])
                res = 1;
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}