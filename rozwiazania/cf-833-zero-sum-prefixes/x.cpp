#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n;
ll a[MAXN], pref[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        pref[0] = 0;
        a[n+1] = 0;
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i-1]+a[i];
        int res = 0;
        int first0 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                first0 = i;
                break;
            }
            if (pref[i] == 0)
                res++;
        }
        if (first0 == 0) {
            cout << res << '\n';
            continue;
        } 
        int last = first0;
        for (int i = first0+1; i <= n+1; i++) {
            if (a[i] == 0) {
                sort(pref+last, pref+i);
                int maxi = 0;
                int act = 1;
                for (int j = last+1; j < i; j++) {
                    if (pref[j] == pref[j-1]) 
                        act++;
                    else 
                        act = 1;
                    maxi = max(maxi, act);
                }
                maxi = max(act, maxi);
                res += maxi;
                last = i;
            }
        }
        cout << res << '\n';

    }
}