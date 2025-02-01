#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 40;
long long h, w, n, d[MAXN];
long long solve(int w, int h) {
    if (w == 0 || h == 0)
        return 0;
    //cout << w << ' ' << h << '\n';
    long long pattern;
    for (int i = n; i > 0; i--) {
        if (d[i] <= w && d[i] <= h) {
            pattern = d[i];
            break;
        }
    }
    long long res = (w/pattern)*(h/pattern);
    res += solve(w%pattern, h);
    res += solve(w-w%pattern, h%pattern);
    return res;

}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> w >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    if (h%d[1] != 0 || w%d[1] != 0) {
        cout << "-1";
        return 0;
    }
    cout << solve(w, h);
}