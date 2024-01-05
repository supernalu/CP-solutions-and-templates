#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAXN = 1e6+10;
int n, a;
int ile[MAXN];
int res = 0;
void Dividors(int n) {
    for (int i = 1; i*i <= n; i++) {
        if (n%i) continue;
        ile[i]++;
        if (n/i != i) ile[n/i]++;
        if (ile[n/i] > 1)
            res = max(res, n/i);
        else if (ile[i] > 1)
            res = max(res, i);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a; Dividors(a);
    }
    cout << res;
    
}