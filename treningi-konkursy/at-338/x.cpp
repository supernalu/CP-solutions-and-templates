#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int q[20], a[20], b[20];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int res = 0;
    int ileA = -1;

    while (true) {
        //cout << ileA << ' ';
        ileA++;
        if (ileA != 0) {
            bool stop = 0;
            for (int i = 1; i <= n; i++) {
                q[i] -= a[i];
                if (0 > q[i])
                    stop = 1;
            }
            if (stop)
                break;
        }
        int ileB = 1e9 + 10;
        for (int i = 1; i <= n; i++) {
            if (b[i] != 0)
                ileB = min(q[i]/b[i], ileB);
            else
                ileB = min(ileB, 1000000000);
        }
        res = max(res, ileA+ileB);
    }
    cout << res;
}