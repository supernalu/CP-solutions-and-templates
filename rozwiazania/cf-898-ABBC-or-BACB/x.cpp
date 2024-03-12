#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
char s[MAXN];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> s+1;
        n = strlen(s+1);
        vector<int> intervals;
        int il = 0;
        int act = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'A') {
                act++;
            }
            else {
                intervals.push_back(act);
                act = 0;
                il++;
            }
        }
        intervals.push_back(act);
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        for (int i = 0; i < min(il, (int)intervals.size()); i++) {
            res += intervals[i];
        }
        cout << res << '\n';
    }
}