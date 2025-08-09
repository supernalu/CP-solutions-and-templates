#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e3+10;
int n, m;
char s[MAXN], t[MAXN];
int dp[MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> s+1 >> t+1;
    n = strlen(s+1); m = strlen(t+1);
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= m; j++)
            dp[i][j] =  max(i, j);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] != t[j])
                dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1});
            else
                dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]});
        }
    }
    cout << dp[n][m];

}