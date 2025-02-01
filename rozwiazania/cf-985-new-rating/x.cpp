#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
constexpr int INF = 1e9 + 10;
int t;
int n, a[MAXN], dp[3][MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++)
                dp[j][i] = INF;
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                
            }
        }
        cout << max(dp[1][n], dp[2][n]) << '\n';
    }
}