#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n, a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int tmp = (res+a[i])/a[i];
            //cout << tmp << ' ';
            res = a[i]*tmp;
        }
        cout << res << '\n';
    }
}