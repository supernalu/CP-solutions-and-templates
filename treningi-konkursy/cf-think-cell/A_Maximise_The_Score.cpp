#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n;
int a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2*n; i++) {
            cin >> a[i];
        }
        sort(a+1, a+2*n+1);
        int res =0;
        for (int i = 1; i <= 2*n; i+= 2)
            res += a[i];
        cout << res << '\n';
    }
}