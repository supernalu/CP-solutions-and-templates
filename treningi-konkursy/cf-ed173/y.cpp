#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int MAXN = 3e5+10;
int t;
ll l, r, g;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> l >> r >> g;
        /*
        ll u = l%g;
        if (u == 0)
            u = g;      
        if (l+2*g-u>r && (g < l || r < g)) {
            cout << "-1 -1\n";
            continue;
        }
        */
        ll L = ((l+g-1)/g)*g;
        ll R = (r/g)*g;
        //cout << L << 
        if (R < L) {
            cout << "-1 -1\n";
            continue;
        }
        while (__gcd(L, R) > g && L <= R) {
            R -= g;
        }
        
        if (R < L) {
            cout << "-1 -1\n";
        }
        else
            cout << L << ' ' << R << '\n';
        
 
 
    }
}