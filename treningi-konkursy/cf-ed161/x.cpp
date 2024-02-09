#include <bits/stdc++.h>
using namespace std;
int t, n;
char a[30], b[30], c[30];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a+1 >> b+1 >> c+1;
        bool res = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == b[i] && b[i] == c[i])
                res = 0;
            else if (a[i] != b[i] && (c[i] == a[i] || c[i] == b[i]))
                res = 0;
        }
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}