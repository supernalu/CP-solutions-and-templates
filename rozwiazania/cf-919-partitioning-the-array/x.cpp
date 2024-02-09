#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, a[MAXN];
int solve(int k) {
    int res = 1;
    int GcdGlobal = 0;
    for (int i = 1; i <= k; i++) {
        int act = a[i], Gcd = 0;
        for (int j = i+k; j <= n; j+=k) {
            Gcd = __gcd(abs(a[j]-act), Gcd);
        }
        GcdGlobal = __gcd(Gcd, GcdGlobal);
        if (GcdGlobal == 1)
                res = 0;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        int res = 0;
        for (int i = 1; i*i <= n; i++) {
            if (n%i != 0)
                continue;
            res += solve(i);
            if (n/i != i)
                res += solve(n/i);
        }
        cout << res << '\n';
    }
}