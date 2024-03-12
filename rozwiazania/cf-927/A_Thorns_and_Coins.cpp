#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n, a[MAXN];
char s[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s+1;
        int res = 0;
        int streak = 0;
        for (int i = 1; i <= n; i++) {
            if (streak > 1)
                break;
            if (s[i] == '*')
                streak++;
            else
                streak = 0;
            if (s[i] == '@')
                res++;
        }
        cout << res << '\n';
    }
}