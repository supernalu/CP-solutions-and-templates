#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + +10;
constexpr long long LIMIT = 1e9;
int t, n;
long long a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long overLimit = 0;
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool pos = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] == 1 && a[i-1] > 1)
                pos = 0;
        }
        if (!pos) {
            cout << "-1\n";
            continue;
        }
        for (int i = 2; i <= n; i++) { 
            while (a[i] <= LIMIT && a[i] < a[i-1]) {
                a[i] *= a[i];
                res++;
            }
            if (a[i] < a[i-1])
                overLimit++;
            res += overLimit;
        }
        cout << res << '\n';
        
    }
}