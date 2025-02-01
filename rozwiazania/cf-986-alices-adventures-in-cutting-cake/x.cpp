#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
typedef long long ll;
int t, n, m;
ll v;
ll a[MAXN], prefSum[MAXN];
int prefRes[MAXN], sufRes[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> v;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prefSum[i] = prefSum[i-1]+a[i];
        }   
        int act = 0;
        for (int i = 1; i <= n; i++) {
            act += a[i];
            prefRes[i] = prefRes[i-1];
            if (act >= v) {
                prefRes[i]++;
                act = 0;
            }
        }
        act = 0;
        sufRes[n+1] = 0;
        for (int i = n; i > 0; i--) {
            act += a[i];
            sufRes[i] = sufRes[i+1];
            if (act >= v) {
                sufRes[i]++;
                act = 0;
            }
        }
        if (max(sufRes[1], prefRes[n]) < m) {
            cout << "-1\n";
            continue;
        }
        int L = 1, R = 1;
        ll res = 0;
        for (; L <= n; L++) {
            while(R <= n && sufRes[R+1]+prefRes[L-1] >= m)
                R++;
            res = max(prefSum[R-1]-prefSum[L-1], res);
        }
        cout << res << '\n';
    }
}