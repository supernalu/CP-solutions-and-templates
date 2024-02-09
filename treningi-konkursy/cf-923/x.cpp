#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5 + 10;
int t, n, k;
int res[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        int mini = 1, maxi = n;
        for (int i = 1; i <= k; i+=2) {
            for (int j = i; j <= n; j+=k) {
                res[j] = mini;
                mini++;
            }
        }
        for (int i = 2; i <= k; i+=2) {
            for (int j = i; j <= n; j+=k) {
                res[j] = maxi;
                maxi--;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
}