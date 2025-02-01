#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t;
long long x, n;
long long a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long  res = 0;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] == 1)
                res += 2;
            else
                res += 1;
        }
        if (res <= sum && n > 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}