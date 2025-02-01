#include <bits/stdc++.h>
using namespace std;
int t, n, x;
set<int> dividors(int k) {
    set<int> res;
    for (int i = 1; i*i <= k; i++) {
        if (k%i)
            continue;
        if (i%2 == 0 && (i+2)/2 >= x)
            res.insert(i);
        if ((k/i)%2 == 0 && (k/i+2)/2 >= x)
            res.insert(k/i);
    }
    return res;
}
int edgeCaseSolver() {
    return dividors(n-1).size();
}
int regSolve() {
    set<int> res1 = dividors(n-x), res2 = dividors(n+x-2);
    set<int> res;
    for (auto it = res1.begin(); it != res1.end(); it++)
        res.insert(*it);
    for (auto it = res2.begin(); it != res2.end(); it++)
        res.insert(*it);
    return res.size();
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> x;
        if (x == 1) {
            cout << edgeCaseSolver() << '\n';
        }
        else {
            cout << regSolve() << '\n';
        }
    }
}
