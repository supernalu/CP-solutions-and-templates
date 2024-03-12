#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n;
int p[MAXN];
int ile[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int st = 0;
        for (int i = 1; i <= n; i++) {
            ile[i] = 0;
            cin >> p[i];
            if (p[i] == i)
                st++;
        }
        for (int i = 1; i <= n; i++) {
            int x = abs(p[i]-i); 
            //cout << x << ' ';
            for (int j = 1; j*j <= x; j++) {
                if (x%j)
                    continue;
                ile[j]++;
                if (j != x/j)
                    ile[x/j]++;
            }
        }
        for (int i = n; i >= 1; i--) {
            //cout << ile[i] << ' ';
            if (ile[i] == n-st) {
                cout << i << '\n';
                break;
            }
        }
    }
}