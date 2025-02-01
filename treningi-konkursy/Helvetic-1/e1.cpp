#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e3 + 10;
constexpr int MOD = 1e9 + 7;
typedef long long ll;
int n, m;
ll s[MAXN], l[MAXN];
ll dp[MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin.tie(0);
    cin >> m >> n; 
    for (int i = 1; i <= m; i++)
        cin >>s[i];
    for (int i = 1; i <= m; i++)
        cin >> l[i];    
    dp[1][0] = 1;
    for (int d = 0; d < n; d++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                dp[j][d+1] += dp[i][d]*(s[i]*s[j]+s[i]*l[j]+s[j]*l[i]);
                dp[j][d+1] %= MOD;
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        res += dp[i][n];
        res %= MOD;
    }
    cout << res;
}