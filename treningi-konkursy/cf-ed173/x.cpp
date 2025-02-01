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

        ll L = ((l+g-1)/g)*g;
        ll R = (r/g)*g;
        //cout << r << ' ' << g << ' '<< r/g << '\n';
        //cout << L << ' ' <<  R << ' ';
        if (R < L) {
            cout << "-1 -1\n";
            continue;
        }
        while (__gcd(L, R) > g && L <= R)
            R-=g;
        //cout <<
        ll Ln = L, Rn = R;
        ll LR = L, RR = R;
        while (Rn < r && Ln <= Rn) {
            //while (__gcd(Ln, Rn) > g && Rn<r) 
                Rn += g;
            if(RR-LR<Rn-Ln && __gcd(Rn, Ln) == g) {
                LR = Ln;
                RR = Rn;
            }
            //cout << Ln << ' ' << Rn << '\n';
            Ln+=g;
        }
        
        if (RR < LR) {
            cout << "-1 -1\n";
        }
        else
            cout << LR << ' ' << RR << '\n';
    }
}