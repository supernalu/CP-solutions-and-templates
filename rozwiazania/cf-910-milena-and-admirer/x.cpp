#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n;
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll res = 0, last = a[n];
        for (int i = n-1; i > 0; i--) {
            if (a[i] <= last)
                last = a[i];
            else  {
                ll tmp = ((a[i]+last-1)/last);
                res += tmp-1;
                last = a[i]/tmp;
            }
        }
        cout << res << '\n';
    }
}