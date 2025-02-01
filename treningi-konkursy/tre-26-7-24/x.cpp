#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t;
int n;
int a[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int mini = 1e9;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mini = min(mini, a[i]);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += min((a[i]+2*mini-2)/(2*mini-1)-1, a[i]/mini-1);
            //cout << res << ' ';
        }
        cout << res << '\n';

    }
    
}