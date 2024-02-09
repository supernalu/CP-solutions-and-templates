#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n, k, b[MAXN];
vector<bool> vis;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vis.assign(n+5, 0);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        bool cycle = 0;
        int maksSciezka = 0;
        int act = n-1;
        vis[n-1] = 1;
        for (int i = 1; i <= n; i++) {
            if (b[act] > n) {
                break;
            }
            maksSciezka++;
            act = (act-b[act]+n)%n;
            if (vis[act] == 1) {
                cycle = 1;
                break;
            }
            vis[act] = 1;
        }
        if (cycle || maksSciezka >= k) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }        
    }
}