#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 10;
int t, n;
int a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    t = 1;
    while (t--) {
        cin >> n;
        map<int, int> m;
        int maxi = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            m[a[i]] = 0;
        }
        for (int i = 1; i <= n; i++) {
            m[a[i]]++;
            maxi = max(maxi, m[a[i]]);
        }
        if (maxi <= n/2) {
            cout << (n+1)/2;
        }
        else {
            int cz1 = n-maxi;
            cout << cz1 + maxi-cz1;
        }

    }
}