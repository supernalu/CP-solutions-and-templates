#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
int p[MAXN], wh[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            wh[p[i]] = i;
        }

        int act = wh[1], res = 0;
        for (int i = 2; i <= n; i++) {
            if (wh[i] > act)
                continue;
            res++;
            act = wh[i];
        }
        cout << res << '\n';
    }
}