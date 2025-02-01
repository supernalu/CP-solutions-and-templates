#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 2e5+10;
constexpr ll MOD = 1e9 + 7;
int t, n;
ll a[MAXN]; 
ll dp[MAXN], prefSum[MAXN], prefPow[MAXN];
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t; 
    while (t--) {
        cin >> n;
        prefSum[0] = 0;
        prefPow[0] = 0;
        a[0] = 1e9 + 10;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int k = a[i];
            prefPow[i] = prefPow[i-1];
            while (k%2 == 0) {
                k /= 2;
                prefPow[i]++;
            }
            prefSum[i] = (prefSum[i-1]+k)%MOD;
        }
        deque<int> monoQ;
        monoQ.push_back(0);
        for (int i = 1; i <= n; i++) {
            while(a[monoQ.back()] <= a[i])
                monoQ.pop_back();
            int v = monoQ.back();
            //cout << v << ' ';
            dp[i] = (fastExp(2, prefPow[i]-prefPow[v], MOD)*a[i])%MOD;
            dp[i] = (dp[i]+prefSum[i-1]-prefSum[v]+MOD)%MOD;
            dp[i] = (dp[i]+dp[v])%MOD;
            cout << dp[i] << ' ';
            monoQ.push_back(i);
        }
        cout << '\n'; 
    }
}