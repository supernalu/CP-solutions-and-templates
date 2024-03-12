#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
typedef long long ll;
int t, n, m, a[MAXN];
char s[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> s+1;
        int L = 1, R = n;
        vector<int> order;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L') {
                order.push_back(L);
                L++;
            }
            else {
                order.push_back(R);
                R--;
            }
        }
        vector<int> res;
        int tmp = 1;
        for (int i = n-1; i >= 0; i--) {
            tmp = (tmp*a[order[i]])%m;
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        for (auto i : res)
            cout << i << ' ';
        cout << '\n';
    }
}