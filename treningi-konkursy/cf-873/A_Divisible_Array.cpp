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
        for (int i = 1; i <= n; i++) {
            a[i] = 2*i;
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}