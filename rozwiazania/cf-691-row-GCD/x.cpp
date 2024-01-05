#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int n, m;
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int mini = 0;
    a[0] = 1e18 + 10;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[mini] > a[i]) {
            mini = i;
        }
    }
    
    ll Gcd = a[1]-a[mini];
    for (int i = 2; i <= n; i++) {
        Gcd = __gcd(Gcd, a[i]-a[mini]);
    }
    for (int i = 1; i <= m; i++) {
        ll b; cin >> b;
        cout << __gcd(Gcd, a[mini]+b) << ' ';
    }
}