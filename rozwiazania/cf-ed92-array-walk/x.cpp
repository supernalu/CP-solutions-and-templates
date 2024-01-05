#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
constexpr int MAXN = 1e5 + 10;
int t, n, k, z;
ll a[MAXN];
ll dp[7][MAXN][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int j= 0; j <= z; j++) {
            for (int i = 1; i <= n; i++) { 
                dp[j][i][0] = 0; dp[j][i][1] = 0;
            }
        }
        dp[0][1][0] = a[1];
        for (int j= 0; j <= z; j++) {
            for (int i = 1; i <= n; i++) {
                if (i < n) {
                    dp[j][i+1][0] = max({dp[j][i+1][0], dp[j][i][0] + a[i+1], dp[j][i][1] + a[i+1]});
                }
                if (i > 1 && j < z)
                    dp[j+1][i-1][1] = max(dp[j+1][i-1][1], dp[j][i][0] + a[i-1]);
            }
        } 
        ll res = 0;
        for (int j= 0; j <= z; j++) {
            for (int i = 1; i <= n; i++) {
                if (i-1+2*j > k) {
                    dp[j][i][0] = 0;
                    dp[j][i][1] = 0;
                }
                res = max({res, dp[j][i][0], dp[j][i][1]});
                //cout << dp[j][i][0] << '|' << dp[j][i][1] << ' ';
            }
            //cout << '\n';
        }
        cout << res << '\n';
    }
}