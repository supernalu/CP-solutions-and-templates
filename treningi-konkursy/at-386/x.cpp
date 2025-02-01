#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5+10;
typedef long long ll;
int n, k;
ll a[MAXN];
ll whole;
ll solveA(int i, int k, ll act) {
    if (k == 0) {
        return act;
    }
    if (n-i+1<k)
        return 0;
    if (n-i+1==k) {
        return solveA(i+1,k-1,(act xor a[i]));
    }
    return max(solveA(i+1,k,act), solveA(i+1, k-1, (act xor a[i])));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        whole = (whole xor a[i]);
    }
    if (k <= n/2)
        cout << solveA(1, k, 0);
    else
        cout << solveA(1, n-k, whole);
}