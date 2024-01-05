#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, k, d;
int a[MAXN], v[MAXN];
int pref[MAXN];
int solve() {
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (pref[i] == i)
            res++;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> d;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= k; i++)
            cin >> v[i];
        a[0] = 0;
        for (int i = 0; i <= n; i++)
            pref[i] = a[i];
         int res = solve() + (d-1)/2;
        for (int i = 1; i <= min(max(k, n), d-1); i++) {
            for (int j = 1; j <= v[(i-1)%k+1]; j++)
                pref[j]++;
            res = max(res, solve() + (d-i-1)/2);
        }
        cout << res << '\n';
    }
}