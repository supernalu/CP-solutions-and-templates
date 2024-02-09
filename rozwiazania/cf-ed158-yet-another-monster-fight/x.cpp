#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, a[MAXN], b[MAXN], c[MAXN], pref[MAXN], suf[MAXN];
bool cmp(int c, int d) {
    if (b[c] == b[d]) {
        return a[c] > a[d];
    }
    return b[c] < b[d];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    t = 1;
    while (t--) {
        cin >> n;
        pref[0] = 0;
        suf[n+1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i] + i-1;
            c[i] = a[i] + n-i;
            pref[i] = max(pref[i-1], c[i]);
        }
        for (int i = n; i > 0; i--) {
            suf[i] = max(suf[i+1], b[i]);
        }
        int res = INT_MAX-1;
        for (int i = 1; i <= n; i++) {
            res = min(res, max({pref[i-1], suf[i+1], a[i]}));
        }
        cout << res << '\n';
    }
}