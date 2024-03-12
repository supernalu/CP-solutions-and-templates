#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
typedef long long ll;
int t, n, m;
int id[MAXN];
pair<int, int> range[MAXN];
vector<int> ending[MAXN];
vector<int> beginning[MAXN];
int maxi[MAXN];
int ile[MAXN];
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            beginning[i].clear();
            ending[i].clear();
        }
        for (int i = 1; i <= m; i++){
            cin >> range[i].first >> range[i].second;
            id[i] = i;
            ending[range[i].second].push_back(i);
            beginning[range[i].first].push_back(i);
        }
        set<tuple<int, int, int>> s;
        dp[0] = 0;
        maxi[0] = 0;
        ile[0] = 0;
        dp[n+1] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (auto j : beginning[i])
                s.insert({range[j].second, range[j].first, j});
            ile[i] = s.size();
            if (ile[i] == 0)
                maxi[i] = i;
            else {
                auto tmp = *(s.rbegin());
                maxi[i] = get<0>(tmp)+1;
            }
            for (auto j : ending[i]) 
                s.erase({range[j].second, range[j].first, j});
        }
        for (int i = 1; i <= n; i++) {
            dp[i+1] = max(dp[i], dp[i+1]);
            dp[maxi[i]] = max(dp[maxi[i]], dp[i]+ile[i]);
        }
        cout << dp[n+1] << '\n';

    }
}