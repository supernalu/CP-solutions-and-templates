#include <bits/stdc++.h>
using namespace std;
int solve(int n, int k, int fixed) {
    cout << n << ' ' << k << ' ' << fixed << '\n';
    int ile;
    if (fixed == 1)
        ile = (n+1)/2;
    else
        ile = n/2;
    if (n == 2 && k == 2 && fixed == 0)
        return 1;
    if (n ==  2 && k == 2 && fixed == 1)
        return 0;
    if (k <= ile && fixed == 1) {
        return 2*k - 1;
    }
    else if (k <= ile && fixed == 0) {
        return 2*k;
    }
    else if (n%2 == 0) {
        return 2*solve(n-ile, k-ile, 1)+(fixed+1)%2;
    }
    else {
        return 2*solve(n-ile, k-ile, 0)+(fixed+1)%2;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        if (n == 1 && k == 1)
            cout << "1\n";
        else
            cout << solve(n, k, 0) << '\n';
    }
}