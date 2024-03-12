#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 998244353;
int t, n;
int a[MAXN];
long long dp[MAXN][4][8];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    t = 1;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int tmp; cin >> tmp;
            a[i] = tmp%2;
        }
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int len = 0; len < 4; len++) {
                for (int mask = 0; mask < 8; mask++) {
                    dp[i][len][mask] += dp[i-1][len][mask];
                    dp[i][len][mask] %= MOD;
                    int newMask = ((mask << 1) % 8) + a[i];
                    if (len < 3 || (len == 3 && ((mask == 0 && newMask == 0) || (mask == 3 && newMask == 6) || (mask == 5 && newMask == 3) || (mask == 6 && newMask == 5)))) {
                        dp[i][min(3, len+1)][newMask] += dp[i-1][len][mask];
                        dp[i][min(3, len+1)][newMask] %= MOD;
                    }
                }
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int len = 0; len < 4; len++) {
        //         for (int mask = 0; mask < 8; mask++) {
        //             cout << dp[i][len][mask] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << "\n\n";
        // }
        long long res = (dp[n][3][0] + dp[n][3][5] + dp[n][3][3]+dp[n][3][6])%MOD;
        cout << res;

    }
}