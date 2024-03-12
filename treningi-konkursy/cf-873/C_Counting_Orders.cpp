#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
constexpr int MOD = 1e9 + 7;
typedef long long ll;
int t, n;
int a[MAXN], b[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }   
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        bool poss = 1;
        
        ll res = 1;
        int ws = 0;
        for (int i = 1; i <= n; i++) {
            while (ws+1 <= n && a[i] > b[ws+1]) {
                ws++;
            }
            res = (res*max(0, ws-i+1))%MOD;
        }
        cout << res << '\n';
    }
}