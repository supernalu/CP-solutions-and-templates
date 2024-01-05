#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 10010;

string s;
vector<int> tree[MAXN];
int dp[2][MAXN];

int gIdx = -1;
void buildTree() {
    ++gIdx;
    int idxCopy = gIdx;
    for (int i = 0; i < s[idxCopy] - '0'; ++i) {
        tree[idxCopy].push_back(gIdx + 1);
        buildTree();
    }
}

void calculateDp(int v, int const & (*minmax)(int const &, int const &)) {
    int dp0 = 0;
    int dp1 = 1;
    if (tree[v].size() == 1) {
        int u = tree[v][0];
        calculateDp(u, minmax);
        dp0 += minmax(dp[0][u], dp[1][u]);
        dp1 += dp[0][u];
    }
    else if (tree[v].size() == 2) {
        int u = tree[v][0];
        int w = tree[v][1];
        calculateDp(u, minmax);
        calculateDp(w, minmax);
        dp0 += minmax(dp[0][u] + dp[1][w], dp[1][u] + dp[0][w]);
        dp1 += dp[0][u] + dp[0][w];
    }
    dp[0][v] = dp0;
    dp[1][v] = dp1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;
    buildTree();

    memset(dp, 0xff, sizeof(dp));
    calculateDp(0, max<int>);
    cout << max(dp[0][0], dp[1][0]) << ' ';

    memset(dp, 0xff, sizeof(dp));
    calculateDp(0, min<int>);
    cout << min(dp[0][0], dp[1][0]) << '\n';
}