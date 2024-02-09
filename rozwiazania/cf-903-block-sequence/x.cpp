#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n;
int a[MAXN], dp[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp[i] = 1e9 + 10;
        }
        dp[1] = 0; dp[n+1] = 1e9 + 10;
        for (int i = 1; i <= n; i++) {
            if (i+a[i]+1 <= n+1) {
                dp[i+a[i]+1] = min(dp[i+a[i]+1], dp[i]);
            }
            dp[i+1] = min(dp[i]+1, dp[i+1]);
        }
        cout << dp[n+1] << '\n';
    }
}