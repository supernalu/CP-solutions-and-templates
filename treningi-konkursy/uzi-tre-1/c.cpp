#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n, k;
int a[MAXN];
int zl[MAXN][2];
int dp[MAXN][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= k; i++) {
        int l[2] = {0, 0};
        for (int j = i; j <= n; j += k) {
            l[a[j]%2]++;
        }
        zl[i][0] = l[0];
        zl[i][1] = l[1];
    }
    dp[0][0] = 0;
    dp[0][1] = 1e9;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][0] + zl[i][1], dp[i-1][1] + zl[i][0]);
        dp[i][1] = min(dp[i-1][1] + zl[i][1], dp[i-1][0] + zl[i][0]);
        //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << dp[k][0] << '\n';
}