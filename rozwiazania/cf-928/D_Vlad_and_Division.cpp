#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
constexpr int BEST = 2147483647;
typedef long long ll;
int t, n;
unsigned int a[MAXN];
bool done[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, vector<int>> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            m[a[i]].clear();
            m[a[i] xor BEST].clear();
            done[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            m[a[i]].push_back(i);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (done[i])
                continue;
            res++;
            if (!m[a[i] xor BEST].empty()) {
                int tmp = m[a[i] xor BEST].back();
                m[a[i] xor BEST].pop_back();
                done[tmp] = 1;
            }
        }
        cout << res << '\n';
        
    }
}
