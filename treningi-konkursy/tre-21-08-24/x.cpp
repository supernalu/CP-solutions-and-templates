#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10; 
typedef long long ll;
int t, n, k, pa, pb;
int p[MAXN];
ll a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> pa >> pb;
        ll resA = 0, resB = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int actA = 0, actB = 0;
        for (int i = 1; i <= min(n, k); i++) {
            actA += a[pa];
            actB += a[pb];
            resA = max(resA, actA + (k-i)*a[pa]);
            resB = max(resB, actB + (k-i)*a[pb]);
            pa = p[pa];
            pb = p[pb];
        }
        //cout << resA << ' ' << resB << '\n';
        if (resA > resB) {
            cout << "Bodya\n";
        }
        else if (resA < resB) {
            cout << "Sasha\n";
        }
        else {
            cout << "Draw\n";
        }
    }
}