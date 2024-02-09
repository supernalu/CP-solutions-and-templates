#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n; 
vector<int> adj[MAXN];
pair<long long, long long> edgeCost[MAXN];
long long A;
vector<long long> pref;
int dp[MAXN];
int binSearch(int l, int r) {
    if (l == r)
        return l;
    int mid = min((l+r+1)/2, r);
    if (pref[mid] > A)
        return binSearch(l, mid-1);
    else
        return binSearch(mid, r);
}

void dfs(int v) {
    long long tmp = *(pref.rbegin());
    pref.push_back(tmp + edgeCost[v].second);
    A += edgeCost[v].first;
    dp[v] = binSearch(0, pref.size()-1);
    for (auto u : adj[v])
        dfs(u);
    pref.pop_back();
    A -= edgeCost[v].first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 2; i <= n; i++) {
            int a, b, c; cin >> a >> b >> c;
            adj[a].push_back(i);
            edgeCost[i] = {b, c}; 
        }
        edgeCost[1] = {0, 0};
        A = 0; pref.clear(); pref.push_back(0);
        dfs(1);
        for (int i = 2; i <= n; i++)
            cout << dp[i]-1 << ' ';
        cout << '\n';
    }
}