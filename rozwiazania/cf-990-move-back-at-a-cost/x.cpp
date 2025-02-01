#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
int t, n;
int a[MAXN];
int mini[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        multiset<int> aEnd;
        a[n+1] = 1e9 + 10;
        mini[n+1] = n+1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = n; i > 0; i--) {
            if (a[i] <= a[mini[i+1]])
                mini[i] = i;
            else
                mini[i] = mini[i+1];
        }
        
        int act = 1;
        while (act<= n && (aEnd.empty() || a[mini[act]] <= *(aEnd.begin()))) {
            //cout << act << ' ';
            int m = mini[act];
            for (; act <= m; act++) {
                if (act == m) {
                    cout << a[act] << ' ';
                    continue;
                }
                aEnd.insert(a[act]+1);
            }
        }
        for (; act <= n; act++)
            aEnd.insert(a[act]+1);
        for (auto i : aEnd)
            cout << i << ' ';
        cout << '\n';
        
    }
}