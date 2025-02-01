#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
constexpr long long MOD = 1e9+7;
typedef long long ll;
int t;
int n;
int a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        deque<ll> monoQ;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            ll tmp = dp[i];
            while (monoQ)
        }
    }
}