#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
typedef long long ll;
int t, n;
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n; 
        for (int i = 1; i <= n; i++) 
            cin >> a[i];    
        ll mini[2], res = a[1], pref = 0;
        mini[0] = 0; mini[1] = a[1];
        for (int i = 1; i <= n; i++) {
            pref += a[i];
            mini[i%2] = min(mini[i%2], pref);
            res = max(res, pref-mini[(i+1)%2]);
        }
        cout << res << '\n';
    }
}