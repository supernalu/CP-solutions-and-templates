#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n, k;
int dp[31];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        dp[30] = 0;
        for (int i = 29; i >= 0; i--) {
            dp[i] = n/(1<<i)-n/(1<<(i+1));
        }
        int ile = 0;
        for (int i = 0; i < 30; i++) {
            if (ile+dp[i] < k) {
                ile += dp[i];
                continue;
            }
            k -= ile;
            cout << (2*k-1)*(1<<i) << '\n';
            break;
        }
    }
}