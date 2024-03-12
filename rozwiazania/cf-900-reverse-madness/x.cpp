#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n, k, l[MAXN], r[MAXN], pairr[MAXN], pref[MAXN];
char s[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s+1;
        for (int i = 1; i <= k; i++) 
            cin >> l[i];
        for (int i = 1; i <= k; i++) {
            cin >> r[i];
            for (int j = l[i]; j <= r[i]; j++) {
                pairr[j] = r[i]+l[i]-j;
                pref[j] = 0;
            }
        }
        int q; cin >> q;
        while (q--) {
            int query; cin >> query;
            int L = min(query, pairr[query]), R = max(query, pairr[query]);
            pref[L]++;
            pref[R+1]--;
        }
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] += pref[i-1];
        }
        for (int i = 1; i <= n; i++) {
            if (i > pairr[i])
                continue;
            if (pref[i]%2 == 1) 
                swap(s[i], s[pairr[i]]);
        }
        cout << s+1 << '\n';
    }
}