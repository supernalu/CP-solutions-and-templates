#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
constexpr long long MOD = 1e9+7;
int t;
int n, a[MAXN], p[MAXN];
bool used[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long res = 1;
        for (long long i = 2; i <= n; i++) {
            res *= i;
            res %= MOD;
        }
        res*=(n);
        res %= MOD;
        res*=(n-1);
        res %= MOD;
        cout << res << '\n';
    }
}