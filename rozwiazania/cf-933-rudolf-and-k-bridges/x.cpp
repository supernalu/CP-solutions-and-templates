#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 110;
constexpr int MAXM = 2e5 + 10;
int t, n, m, k, d;
ll a[MAXM];
ll dp[MAXM];
ll partRes[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                cin >> a[j];
    
            deque<int> monoQueId;
            dp[1] = 1;
            monoQueId.push_back(1);
            for (int j = 2; j <= m; j++) {
                while (j-monoQueId.front() - 1 > d)
                    monoQueId.pop_front();
                dp[j] = a[j]+1+dp[monoQueId.front()];
                while (!monoQueId.empty() && dp[j] <= dp[monoQueId.back()])
                    monoQueId.pop_back();
                monoQueId.push_back(j);
            }
            partRes[i] = dp[m];
        }
        ll res = 0;
        ll tmp;
        for (int i = 1; i <= k; i++) {
            res += partRes[i];
        }
        tmp = res;
        for (int i = k+1; i <= n; i++) {
            tmp = tmp-partRes[i-k]+partRes[i];
            res = min(res, tmp);
        }
        cout << res << '\n';
    }
}