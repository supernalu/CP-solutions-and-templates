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
        //cout << (l < r);
        ll L = ((l+g-1)/g)*g;
        ll R = (r/g)*g;
        //cout << L << ' ' <<  R << ' ';
        if (R < L) {
            cout << "-1 -1\n";
            continue;
        }
        ll Ln = L, Rn = 0;
        ll LR = 0, RR = -1;
        int i = 0;
        while (Rn < R && i < 1000 && Ln <= r) {
            Rn = R;
            while (__gcd(Ln, Rn) > g && Ln<=Rn) 
                Rn -= g;
            if(RR-LR<Rn-Ln && __gcd(Rn, Ln) == g) {
                LR = Ln;
                RR = Rn;
            }
            //cout << Ln << ' ' << Rn << '\n';
            Ln+=g;
            i++;
        }
        
        if (RR < LR) {
            cout << "-1 -1\n";
        }
        else
            cout << LR << ' ' << RR << '\n';
        
 
 
    }
}