#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
int n;
int d[MAXN], t[MAXN], id[MAXN];
bool cmp(int a, int b) {
    return t[a] > t[b];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> t[i];
        id[i] = i;
    }
    sort(id+1, id+n+1, cmp);
    int res = 1e9+10;
    for (int i = 1; i <= n; i++) {
        res = min(res-d[id[i]], t[id[i]]-d[id[i]]);
    }
    cout << res;
}