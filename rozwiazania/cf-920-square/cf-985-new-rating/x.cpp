#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5+10;
constexpr int INF = 1e9 + 10;
int t, n;
int a[MAXN]; 
int dp[MAXN][3];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t; 
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 3; j++)
                dp[i][j] = -INF;
        }
        dp[0][0] = 0;
        dp[0][1] = -INF;
        dp[0][2] = -INF;
        for (int i = 0; i < n; i++) {
            if (a[i+1] > dp[i][0])
                dp[i+1][0] = dp[i][0]+1;
            else if (a[i+1] == dp[i][0])
                dp[i+1][0] = dp[i][0];
            else
                dp[i+1][0] = dp[i][0]-1;
            dp[i+1][1] = max(dp[i][1], dp[i][0]);
            if (a[i+1] > dp[i][2])
                dp[i+1][2] = dp[i][2]+1;
            else if (a[i+1] == dp[i][2])
                dp[i+1][2] = dp[i][2];
            else
                dp[i+1][2] = dp[i][2]-1;
            dp[i+1][2] = max(dp[i+1][2], dp[i][1]);
        }
        cout << max(dp[n][1], dp[n][2]) << '\n';
    }
}