#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 10;
constexpr int MOD = 1e9 + 7;
typedef long long ll;
int t, n, m, a[MAXN];
ll fastExp(ll a, ll b, ll MOD) { 
    if (b == 0)
        return 1;
    ll tmp = fastExp(a, b/2, MOD);
    tmp = (tmp*tmp)%MOD;
    if (b%2)
        return (tmp*a)%MOD;
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        map<int, int> ile;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ile[a[i]] = 0;
        }
        a[0] = 0;
        sort(a+1, a+n+1);
        vector<int> noRepeats;
        for (int i = 1; i <= n; i++) {
            ile[a[i]]++;
            if (a[i] != a[i-1])
                noRepeats.push_back(a[i]);
        }
        long long res = 0;
        long long act = 1;
        if (noRepeats.size() < m) {
            cout << res << '\n';
            continue;
        }
        for (int i = 0; i < m; i++) {
            act = (act*ile[noRepeats[i]])%MOD;
        }
        if (noRepeats[m-1]-noRepeats[0] == m-1) {
            res += act;
        }
        for (int i = 0; i < noRepeats.size()-m; i++) {
            act = (act*fastExp(ile[noRepeats[i]], MOD-2, MOD))%MOD;
            act = (act*ile[noRepeats[i+m]])%MOD;
            if (noRepeats[i+m]-noRepeats[i+1] == m-1) {
                res += act;
                res %= MOD;
            }
        }
        cout << res << '\n';
    }
}