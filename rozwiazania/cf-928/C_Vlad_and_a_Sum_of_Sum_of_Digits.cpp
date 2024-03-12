#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
typedef long long ll;
int t, n;
long long dp[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    dp[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        ll tmp = 0;
        ll j = i;
        while (j != 0) {
            tmp += j%10;
            j /= 10;
        }
        dp[i] = dp[i-1]+tmp;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}