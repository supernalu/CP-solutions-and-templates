#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n;
int p[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int maxi = n, mini = 1;
        for (int i = 1; i <= n; i+=2) {
            p[i] = maxi;
            maxi--;
        }
        for (int i = 2; i <= n; i+=2) {
            p[i] = mini;
            mini++;
        }
        for (int i = 1; i <= n; i++)
            cout << p[i] << ' ';
        cout << '\n';
    }
}