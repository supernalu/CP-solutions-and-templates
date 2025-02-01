#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 3e5 + 10;
int t, n, a[MAXN], last[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> t; 
    while (t--) {
        cin  >> n; 
        int gcd = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            gcd = __gcd(gcd, a[i]);
        }
        cout << a[n]/gcd << '\n';



        

    }
}