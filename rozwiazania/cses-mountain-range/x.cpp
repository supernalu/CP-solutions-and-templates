#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
int n;
pair<int,int> h[MAXN];
int dp[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }
    int res = 0;
    sort(h+1, h+n+1);
    set<int> s;
    s.insert(0);
    s.insert(n+1);
    dp[0] = 0;
    dp[n+1] = 0;
    for (int i = n; i > 0; i--) {
        auto left = s.lower_bound(h[i].second); left--;
        auto right = s.upper_bound(h[i].second);
        dp[h[i].second] = max(dp[*left], dp[*right])+1;  
        res = max(res, dp[h[i].second]);
        if (h[i].first > h[i-1].first) {
            int j = i;
            while (h[j].first == h[i].first) {
                s.insert(h[j].second);
                j++;
            }
        }
    }
    cout << res << '\n';
}