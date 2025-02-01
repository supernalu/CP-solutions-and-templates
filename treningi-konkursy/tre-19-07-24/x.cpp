#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6+10;
constexpr int INF = 1e9 + 10;
int t;
int n, m;
int act[MAXN];
int dp[2][MAXN][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int actO = 0;
    int actC = 0;
    int j = 1;
    for (int i = 0; i <= 500000; i++) {
        if (j > 1e6)
            break;
        for (int k = 1; k <= 4*i+1; k++) {
            dp[actO][j][actC] = dp[actO][j-1][actC]+1;
            dp[actO][j][(actC+1)%2] = dp[actO][j-1][(actC+1)%2];
            dp[(actO+1)%2][j][actC] = dp[(actO+1)%2][j-1][actC];
            dp[(actO+1)%2][j][(actC+1)%2] = dp[(actO+1)%2][j-1][(actC+1)%2];
            actC = (actC+1)%2;
            j++;
            if (j > 1e6)
            break;
        }
        actO = (actO+1)%2;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[0][n][0] << ' ' << dp[0][n][1] << ' ' << dp[1][n][0] << ' ' << dp[1][n][1] << '\n';
    }
    
    

    
}