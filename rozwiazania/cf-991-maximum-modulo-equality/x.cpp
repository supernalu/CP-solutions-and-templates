#include <bits/stdc++.h>
using namespace std;
constexpr int LEAVES = 1 << 20;
int t, n, q;
int a[LEAVES+1];
int segTree[2*LEAVES];
int l[2*LEAVES], r[2*LEAVES];
void firstInitation() {
    for (int i = LEAVES; i < 2*LEAVES; i++) {
        l[i] = i-LEAVES;
        r[i] = i-LEAVES;
    }
    for (int i = LEAVES-1; i > 0; i--) {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
    }
}

int query(int L, int R, int v) {
    if (r[v] < L || R < l[v])
        return 0;
    if (L <= l[v] && r[v] <= R)
        return segTree[v];
    return __gcd(query(L, R, 2*v), query(L, R, 2*v+1));
}
void update(int k, int v) {
    v += LEAVES;
    segTree[v] = k;
    v /= 2;
    while (v > 0) {
        segTree[v] = __gcd(segTree[2*v], segTree[2*v+1]);
        v /= 2;
    }
}
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    firstInitation();
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) 
            cin >> a[i]; 
        for (int i = 1; i < n; i++)
            update(abs(a[i]-a[i+1]), i);
        while (q--) {
            int l, r; cin >> l >> r;
            if (l == r)
                cout << "0 ";
            else 
                cout << __gcd(query(l, r-1, 1), abs(a[r]-a[l])) << ' ';
        }
        cout << '\n';
    }
}