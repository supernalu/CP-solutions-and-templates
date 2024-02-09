#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
constexpr int MAXVAL = 1e6 + 10;
int t, n, m, k;
int a[MAXN], b[MAXN];
bool inA[MAXVAL], inB[MAXVAL];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        bool res = 1;
        for (int i = 0; i <= k; i++) {
            inA[i] = 0;
            inB[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            inA[a[i]] = 1;
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
            inB[b[i]] = 1;
        }
        int ileA = 0, ileB = 0;
        for (int i = 1; i <= k; i++) {
            if (inA[i] == 0 && inB[i] == 0) {
                res = 0;
                break;
            }
            if (inA[i] == 1 && inB[i] == 1)
                continue;
            if (inA[i] == 1) {
                ileA++;
            }
            else
                ileB++;
        }
        if (ileA > k/2 || ileB > k/2)
            res = 0;
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}