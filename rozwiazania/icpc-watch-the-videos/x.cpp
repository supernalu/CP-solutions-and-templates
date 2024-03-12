#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 4e5 + 10;
typedef long long ll;
int n, m;
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    for (; r > l; r--) {
        if (a[r] +a[l] <= m) 
            l++;
        else 
            res++; 
    }
    
    cout << res << '\n';
}