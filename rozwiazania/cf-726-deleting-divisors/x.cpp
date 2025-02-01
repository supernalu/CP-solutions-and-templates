#include <bits/stdc++.h>
using namespace std;
int t, n;
int dp[2][100];
int main() {
    dp[0][1] = 1;
    dp[1][1] = 0;
    cin >> n;
    cout << "1: 1\n";
    for (int i = 2; i <= n; i++) {
        bool CanAliceWin = 0, canBobWin = 0;
        for (int j = 2; j*j <= i; j++) {
            if (i%j != 0)
                continue;
            if (dp[1][i-j] == 0 || dp[1][i-i/j] == 0)
                CanAliceWin = 1;
            if (dp[0][i-j] == 1 || dp[0][i-i/j] == 1)
                canBobWin = 1;
        }
        if (CanAliceWin) {
            dp[0][i] = 0;
        }
        else {
            dp[0][i] = 1;
        }
        if (canBobWin) {
            dp[1][i] = 1;
        }
        else {
            dp[1][i] = 0;
        }
        cout << i << ": " << dp[0][i] << '\n';
    }
}
